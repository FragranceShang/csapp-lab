//尚久芳 21307130068

#include "cachelab.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *optarg;
extern int optind, opterr, optopt;

//十六进制字符转成十进制整数
long htoi(char *s){
   long n = 0;
   for(int i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'); i++){
      if(s[i] > '9')
         n = 16 * n + (10 + s[i] - 'a');
      else n = 16 * n + (s[i] - '0');
   }
   return n;
}

struct row{
   int valid;     //有效位
   int tag;       //标记位
};

struct LRU_set{
   struct list *head;   //链表头
   struct row *E_row;   //组
};

struct list{
   struct list *prior;  //指向直接前趋
   struct list *next;   //指向直接后继
   int tag;          //标记
};


int main(int argc, char *argv[]){
   int hit_count = 0, miss_count = 0, eviction_count = 0;  //命中，未命中，驱逐
   int opt;
   int s = 0;      //高速缓存组S=2^s
   int E = 0;      //高速缓存行E
   int b = 0;      //数据块B=2^b
   int v = 0;  //是否查看过程信息
   char *file_name;
   FILE *file;
   //提示(帮助)的信息
   char help[] = "Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n"
                 "Options:\n"
            	"-h          Print this help message.\n"
            	"-v          Optional verbose flag.\n"
            	"-s <num>    Number of set index bits.\n"
            	"-E <num>    Number of lines per set.\n"
            	"-b <num>    Number of block offset bits.\n"
            	"-t <file>   Trace file.\n\n"
            	"Examples:\n"
            	"linux>     %s  -s 4 -E 1 -b 4 -t traces/yi.trace\n"
            	"linux>     %s  -v -s 8 -E 2 -b 4 -t traces/yi.trace\n";
   //"sEbt:hv"：-s、-E、-b、-t 可接收字符，-h和-v不接收
   while ((opt = getopt(argc, argv, "sEbt:hv")) != -1) {
      switch (opt) {
         case 'h':  
            fprintf(stderr, help, argv[0], argv[0], argv[0]);  //argv[0]是命令行参数的第一个值，即运行的可执行文件名
            exit(0);
         case 'v':
            v = 1;
            break;
         case 's':                        
            s = atoi(argv[optind]);   //atoi字符转十进制
            break;
         case 'E':                        
            E = atoi(argv[optind]);
            break;
         case 'b':                       
            b = atoi(argv[optind]);
            break;
         case 't':
            file_name = argv[optind-1];     //获取文件名
            file = fopen(file_name,"r");  //打开文件
            if(file == NULL){
               perror(file_name);
               exit(EXIT_FAILURE);
            }
            break;
         default:
            fprintf(stderr, help, argv[0], argv[0], argv[0]);
            exit(EXIT_FAILURE);
      }
   }
   //设置模拟缓存。初始化。S=2^s组，即1<<s。
   int S = 1 << s;
   struct LRU_set cache[S];
   for(int i = 0; i < S; i++){
      cache[i].head = (struct list*)malloc(sizeof(struct list));
      cache[i].head->tag = -1;
      cache[i].E_row = malloc(sizeof(struct row)*E);
      for(int j = 0; j < E; j++){
         cache[i].E_row[j].valid =0 ;    
         cache[i].E_row[j].tag = -1;
      }
   }
   char ch[16];                     //刚好可以容纳一行数据的大小
   const char Separator[] = " ,";    //分隔符
   char *token;                     //子串
   while(fgets(ch, 16, file) != NULL){
      token = strtok(ch, Separator);
      char *instruction = token;       //内存访问的类型
      if (*instruction == 'I')         //I类型不用处理
         continue;
      token = strtok(NULL, Separator);
      char *address_char = token;       //地址的字符表示
      long address = htoi(address_char); //地址的十进制表示
      token = strtok(NULL,Separator);
      int size = atoi(token);  
      int set_index = (address >> b) % (1 << s);  //组索引
      int tag = address >> (s + b);                     //标记位  
      if(v) printf("%s %s,%d ", instruction, address_char, size);
      int M = *instruction == 'M' ? 2 : 1;          //'M' 循环两遍,'S''I'一遍
      while(M--){
      	 int flag = 0;
         struct LRU_set *lru_row = &cache[set_index];   //获取该组
         struct list *head = lru_row->head;     //获取该组的双链表头
         for(int i = 0; i < E; i++){                    //遍历一组中的所有行
            struct row *arow = &lru_row->E_row[i]; //获取一行
            if(arow->valid && arow->tag == tag){     //有效且标记相同则命中
                  //找到双链表中命中的缓存，准备放到链表头
                  while(head->tag != tag)
                     head = head->next;
                  //放到链表头，要判断，是不是本身就是头，是头就跳过
                  if (head != lru_row->head){
                     head->prior->next = head->next;
                     //判断是不是链表尾，是尾就跳过
                     if(head->next != NULL)
                        head->next->prior = head->prior;
                     head->prior = NULL;
                     head->next = lru_row->head;
                     lru_row->head->prior = head;
                     lru_row->head = head;
                  }
                  hit_count++;                        //命中
                  if(v) printf("hit ");
                  flag = 1;
                  break;
            }
         }
         if (flag){
             if (v && !M) printf("\n");
             continue;
         }
         	
         for(int i = 0;i < E;i++){      //无效：未命中，要写入无效的缓存区
            struct row *arow = &lru_row->E_row[i]; //获取一行
            if(!arow->valid){ 
               //准备放入链表的新结点
               struct list * temp = (struct list*)malloc(sizeof(struct list));
               temp->prior = NULL;
               temp->next = NULL;
               temp->tag = tag;  
               //判断是不是链表中的第一个结点，是就跳过
               if(head->tag != -1){
                  temp->next = head;
                  head->prior = temp;
               }
               //设置尾头结点
               lru_row->head = temp;
               miss_count++;                           //未命中   
               arow->valid = 1;
               arow->tag = tag;
               if(v) printf("miss ");
               flag = 1;
                  break;
            }
         }
         if (flag){
             if (v && !M) printf("\n");
             continue;
         }
         /*
          	又没命中，又没有多余的缓存区，则驱逐。驱逐的是双链表的最后一个
         	 驱逐就是把双链表最后一个移到开头并重新设置tag
          */
         while(head->next != NULL)
            head = head->next;
         //判断链表中是不是只有一个结点，是就跳过
         if (head != lru_row->head){
            head->prior->next = NULL;
            head->prior = NULL;
            head->next = lru_row->head;
            lru_row->head->prior = head;
            lru_row->head = head;
         }
         //找到在缓存中对应与双链表最后一个的缓存，移除，写入新的缓存。
         struct row *arow;
         for(int j = 0; j < E; j++){
            arow = &cache[set_index].E_row[j];
            if(head->tag == arow->tag)
               break;
         }
         head->tag = tag;
         arow->tag = tag;
         if(v) printf("miss eviction");
         miss_count++;        //未命中
         eviction_count++;    //驱逐
         if (v && !M) printf("\n");            //不是'M'就要换行
      }
   }
   //释放分配的空间
   for (int i = 0; i < S; i++){
      free(cache[i].head);
      free(cache[i].E_row);
   }
   printSummary(hit_count, miss_count, eviction_count);
   return 0;
}



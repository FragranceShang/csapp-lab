/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if(q==NULL)
    	return NULL;
    q->tail = NULL;
    q->head = NULL;
    q->size=0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    if(q){
    	if(q->head){
    	    list_ele_t *current=q->head;
    	    while(current){
    	        list_ele_t *temp=current;
    	        current=temp->next;
    	        free(temp->value);
    	        free(temp);
    	    }
    	}
    	free(q);
    }
    
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if(q==NULL) return false;
    
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if(newh==NULL) return false;
    newh->value=malloc(strlen(s)+1);
    if(newh->value==NULL) {
    	free(newh);
    	return false;
    }
    strcpy(newh->value,s);
    if(q->tail==NULL) q->tail=newh;
    q->size++;
    
    newh->next = q->head;
    q->head = newh;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remembert: It should operate in O(1) time */
    if(q==NULL) return false;
    list_ele_t *newh;
    newh=malloc(sizeof(list_ele_t));
    if(newh==NULL) return false;
    newh->value=malloc(strlen(s)+1);
    if(newh->value==NULL){
    	free(newh);
    	return false;
    }
    strcpy(newh->value,s);
    if(q->tail) q->tail->next=newh;
    q->tail=newh;
    newh->next=NULL;
    if(q->head==NULL) q->head=newh;
    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if(q==NULL||q->head==NULL) return false;
    if(sp==NULL) return false;
    char*str=q->head->value;
    if(strlen(str)>=bufsize){
    	char s[bufsize];
    	strncpy(s,str,bufsize-1);
    	s[bufsize-1]='\0';
    	strcpy(sp,s);
    }
    else strcpy(sp,str);
    free(str);
    list_ele_t *cur=q->head;
    q->head = q->head->next;
    if(q->tail==cur) q->tail=NULL; 
    free(cur);
    q->size--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if(q==NULL||q->head==NULL) return 0;
    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if(q&&q->head){
    	q->tail=q->head;
    	list_ele_t *fro=q->head,*las=q->head->next;
    	q->head->next=NULL;
    	while(las!=NULL){
    	    list_ele_t *temp=las->next;
    	    las->next=fro;
    	    fro=las;
    	    las=temp;
    	}    
    	q->head=fro;    
    	
    }
}


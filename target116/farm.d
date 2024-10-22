
farm.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <start_farm>:
   0:	f3 0f 1e fa          	endbr64 
   4:	b8 01 00 00 00       	mov    $0x1,%eax
   9:	c3                   	ret    

000000000000000a <addval_314>:
   a:	f3 0f 1e fa          	endbr64 
   e:	8d 87 51 36 58 c3    	lea    -0x3ca7c9af(%rdi),%eax
  14:	c3                   	ret    

0000000000000015 <setval_245>:
  15:	f3 0f 1e fa          	endbr64 
  19:	c7 07 58 c1 cc 82    	movl   $0x82ccc158,(%rdi)
  1f:	c3                   	ret    

0000000000000020 <addval_246>:
  20:	f3 0f 1e fa          	endbr64 
  24:	8d 87 48 89 c7 94    	lea    -0x6b3876b8(%rdi),%eax
  2a:	c3                   	ret    

000000000000002b <addval_110>:
  2b:	f3 0f 1e fa          	endbr64 
  2f:	8d 87 58 90 c3 42    	lea    0x42c39058(%rdi),%eax
  35:	c3                   	ret    

0000000000000036 <setval_181>:
  36:	f3 0f 1e fa          	endbr64 
  3a:	c7 07 48 89 c7 94    	movl   $0x94c78948,(%rdi)
  40:	c3                   	ret    

0000000000000041 <getval_451>:
  41:	f3 0f 1e fa          	endbr64 
  45:	b8 50 90 90 90       	mov    $0x90909050,%eax
  4a:	c3                   	ret    

000000000000004b <getval_412>:
  4b:	f3 0f 1e fa          	endbr64 
  4f:	b8 48 89 c7 c3       	mov    $0xc3c78948,%eax
  54:	c3                   	ret    

0000000000000055 <getval_487>:
  55:	f3 0f 1e fa          	endbr64 
  59:	b8 8f 48 89 c7       	mov    $0xc789488f,%eax
  5e:	c3                   	ret    

000000000000005f <mid_farm>:
  5f:	f3 0f 1e fa          	endbr64 
  63:	b8 01 00 00 00       	mov    $0x1,%eax
  68:	c3                   	ret    

0000000000000069 <add_xy>:
  69:	f3 0f 1e fa          	endbr64 
  6d:	48 8d 04 37          	lea    (%rdi,%rsi,1),%rax
  71:	c3                   	ret    

0000000000000072 <getval_491>:
  72:	f3 0f 1e fa          	endbr64 
  76:	b8 81 ce 38 d2       	mov    $0xd238ce81,%eax
  7b:	c3                   	ret    

000000000000007c <addval_238>:
  7c:	f3 0f 1e fa          	endbr64 
  80:	8d 87 89 ce 92 90    	lea    -0x6f6d3177(%rdi),%eax
  86:	c3                   	ret    

0000000000000087 <setval_182>:
  87:	f3 0f 1e fa          	endbr64 
  8b:	c7 07 89 c2 30 c0    	movl   $0xc030c289,(%rdi)
  91:	c3                   	ret    

0000000000000092 <setval_391>:
  92:	f3 0f 1e fa          	endbr64 
  96:	c7 07 89 d1 38 db    	movl   $0xdb38d189,(%rdi)
  9c:	c3                   	ret    

000000000000009d <setval_398>:
  9d:	f3 0f 1e fa          	endbr64 
  a1:	c7 07 a9 c2 38 d2    	movl   $0xd238c2a9,(%rdi)
  a7:	c3                   	ret    

00000000000000a8 <getval_498>:
  a8:	f3 0f 1e fa          	endbr64 
  ac:	b8 48 89 e0 91       	mov    $0x91e08948,%eax
  b1:	c3                   	ret    

00000000000000b2 <addval_118>:
  b2:	f3 0f 1e fa          	endbr64 
  b6:	8d 87 c9 c2 c3 25    	lea    0x25c3c2c9(%rdi),%eax
  bc:	c3                   	ret    

00000000000000bd <getval_228>:
  bd:	f3 0f 1e fa          	endbr64 
  c1:	b8 89 ce 38 c9       	mov    $0xc938ce89,%eax
  c6:	c3                   	ret    

00000000000000c7 <getval_476>:
  c7:	f3 0f 1e fa          	endbr64 
  cb:	b8 89 d1 c7 cb       	mov    $0xcbc7d189,%eax
  d0:	c3                   	ret    

00000000000000d1 <setval_474>:
  d1:	f3 0f 1e fa          	endbr64 
  d5:	c7 07 a9 c2 20 db    	movl   $0xdb20c2a9,(%rdi)
  db:	c3                   	ret    

00000000000000dc <setval_187>:
  dc:	f3 0f 1e fa          	endbr64 
  e0:	c7 07 48 89 e0 c3    	movl   $0xc3e08948,(%rdi)
  e6:	c3                   	ret    

00000000000000e7 <addval_446>:
  e7:	f3 0f 1e fa          	endbr64 
  eb:	8d 87 48 8d e0 c3    	lea    -0x3c1f72b8(%rdi),%eax
  f1:	c3                   	ret    

00000000000000f2 <getval_490>:
  f2:	f3 0f 1e fa          	endbr64 
  f6:	b8 09 ce 84 d2       	mov    $0xd284ce09,%eax
  fb:	c3                   	ret    

00000000000000fc <setval_423>:
  fc:	f3 0f 1e fa          	endbr64 
 100:	c7 07 89 c2 38 c0    	movl   $0xc038c289,(%rdi)
 106:	c3                   	ret    

0000000000000107 <getval_172>:
 107:	f3 0f 1e fa          	endbr64 
 10b:	b8 48 09 e0 90       	mov    $0x90e00948,%eax
 110:	c3                   	ret    

0000000000000111 <getval_189>:
 111:	f3 0f 1e fa          	endbr64 
 115:	b8 55 09 d1 90       	mov    $0x90d10955,%eax
 11a:	c3                   	ret    

000000000000011b <setval_144>:
 11b:	f3 0f 1e fa          	endbr64 
 11f:	c7 07 81 ce 08 db    	movl   $0xdb08ce81,(%rdi)
 125:	c3                   	ret    

0000000000000126 <getval_404>:
 126:	f3 0f 1e fa          	endbr64 
 12a:	b8 89 ce 94 d2       	mov    $0xd294ce89,%eax
 12f:	c3                   	ret    

0000000000000130 <addval_184>:
 130:	f3 0f 1e fa          	endbr64 
 134:	8d 87 48 89 e0 c1    	lea    -0x3e1f76b8(%rdi),%eax
 13a:	c3                   	ret    

000000000000013b <getval_388>:
 13b:	f3 0f 1e fa          	endbr64 
 13f:	b8 a9 d1 90 90       	mov    $0x9090d1a9,%eax
 144:	c3                   	ret    

0000000000000145 <getval_151>:
 145:	f3 0f 1e fa          	endbr64 
 149:	b8 89 d1 18 c9       	mov    $0xc918d189,%eax
 14e:	c3                   	ret    

000000000000014f <addval_370>:
 14f:	f3 0f 1e fa          	endbr64 
 153:	8d 87 81 d1 20 c9    	lea    -0x36df2e7f(%rdi),%eax
 159:	c3                   	ret    

000000000000015a <setval_207>:
 15a:	f3 0f 1e fa          	endbr64 
 15e:	c7 07 48 89 e0 91    	movl   $0x91e08948,(%rdi)
 164:	c3                   	ret    

0000000000000165 <getval_226>:
 165:	f3 0f 1e fa          	endbr64 
 169:	b8 89 ce 78 d2       	mov    $0xd278ce89,%eax
 16e:	c3                   	ret    

000000000000016f <setval_477>:
 16f:	f3 0f 1e fa          	endbr64 
 173:	c7 07 89 ce 20 c0    	movl   $0xc020ce89,(%rdi)
 179:	c3                   	ret    

000000000000017a <addval_316>:
 17a:	f3 0f 1e fa          	endbr64 
 17e:	8d 87 89 c2 30 c0    	lea    -0x3fcf3d77(%rdi),%eax
 184:	c3                   	ret    

0000000000000185 <getval_307>:
 185:	f3 0f 1e fa          	endbr64 
 189:	b8 89 d1 48 d2       	mov    $0xd248d189,%eax
 18e:	c3                   	ret    

000000000000018f <getval_171>:
 18f:	f3 0f 1e fa          	endbr64 
 193:	b8 89 d1 38 c0       	mov    $0xc038d189,%eax
 198:	c3                   	ret    

0000000000000199 <getval_216>:
 199:	f3 0f 1e fa          	endbr64 
 19d:	b8 96 09 c2 c3       	mov    $0xc3c20996,%eax
 1a2:	c3                   	ret    

00000000000001a3 <setval_244>:
 1a3:	f3 0f 1e fa          	endbr64 
 1a7:	c7 07 48 89 e0 c3    	movl   $0xc3e08948,(%rdi)
 1ad:	c3                   	ret    

00000000000001ae <addval_284>:
 1ae:	f3 0f 1e fa          	endbr64 
 1b2:	8d 87 1e ba 89 c2    	lea    -0x3d7645e2(%rdi),%eax
 1b8:	c3                   	ret    

00000000000001b9 <getval_223>:
 1b9:	f3 0f 1e fa          	endbr64 
 1bd:	b8 e5 08 89 e0       	mov    $0xe08908e5,%eax
 1c2:	c3                   	ret    

00000000000001c3 <end_farm>:
 1c3:	f3 0f 1e fa          	endbr64 
 1c7:	b8 01 00 00 00       	mov    $0x1,%eax
 1cc:	c3                   	ret    

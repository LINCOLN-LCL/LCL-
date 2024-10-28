#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<memory.h>
using namespace std;
struct page{
int pagenumber;
int memorynumber;
int IsInmemory;
};
typedef page PAGE;
PAGE *PageTable;
/***************************************
入口参数：
page_size:页的个数
requestsize:随机访问串的长度
memorysize:内存帧的个数
random:随机产生的访问串数组
*************************************/
void FIFO(int page_size,int requestsize,int memorysize,int *random)
{
 int *memory;//模拟内存
memory = (int*)malloc(sizeof(int)*memorysize);
 PageTable = (PAGE*)malloc(sizeof(PAGE)*page_size);
int i,j;
for(i=0;i<memorysize;i++)
memory[i] = -1;
 for(i = 0;i<page_size;i++){
PageTable[i].IsInmemory = 0;
PageTable[i].memorynumber = -1;
PageTable[i].pagenumber = i;
}
int PageFalseTime = 0;//记录缺页的次数
int FirstIn = 0;//记录最先进入内存的页
int FullNumber = 0;//记录物理块是否已经被占满
int index = 0;//随机访问串数组的起始下标
while(FullNumber != memorysize)
{
if(PageTable[random[index]].IsInmemory == 0){
 cout<<"页"<<random[index]<<" 不在内存中"<<endl;
 memory[FullNumber] = random[index];//将页面装入内存中
PageTable[random[index]].IsInmemory = 1;
PageTable[random[index]].memorynumber = FullNumber;
FullNumber++;
index++;
PageFalseTime++;
}
else if(PageTable[random[index]].IsInmemory == 1){
cout<<"页"<<random[index]<<" 在内存中"<<endl;
index++;
}
}
int next_index = index;
for(index = next_index;index<requestsize;index++)
{
if(PageTable[random[index]].IsInmemory == 1){
cout<<"页"<<random[index]<<" 在内存中"<<endl;
}
else{
PageFalseTime++;
memory[FirstIn]=random[i];
for(j=0;j<requestsize;j++){
if(PageTable[j].memorynumber==FirstIn){
cout<<" 页 "<<random[index]<<" 不 在 内 存 中 ,"<<" 替 换 页"<<j<<endl;
 PageTable[j].memorynumber = -1;
PageTable[j].IsInmemory = 0;
break;
}
}
PageTable[random[index]].IsInmemory = 1;
 PageTable[random[index]].memorynumber = FirstIn;
FirstIn = (FirstIn + 1)%memorysize;
}
}
 cout<<"缺页次数为:"<<PageFalseTime<<endl;
cout<<"缺页率为:"<<(double)PageFalseTime/requestsize*100<<"%"<<endl;
free(memory);
 free(PageTable);
}

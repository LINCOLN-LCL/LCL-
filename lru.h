#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<memory.h>
using namespace std;
struct memory{
int pagenumber;
int access_time;
};
typedef memory MEMORY;
MEMORY *MEMORYTable;
int selectMax(MEMORY *b,int memory_size){
int tag = 0;
int max = -1;
for(int k=0;k<memory_size;k++){
if(b[k].access_time>max){
max = b[k].access_time;
tag = k;
}
}
return tag;
}
int PositionOfMemory(MEMORY *b,int NO,int memory_size){
for(int i=0;i<memory_size;i++){
if(b[i].pagenumber == NO){
return i;
}
}
return -1;
}
void lru(int memorysize,int random_size,int *random){
MEMORYTable = (MEMORY*)malloc(sizeof(MEMORY)*memorysize);
int page_fault_time = 0;
for(int i=0;i<memorysize;i++){
MEMORYTable[i].pagenumber = -1;
MEMORYTable[i].access_time = random_size-i-1;
}
int value;
int k,l;
for(int i=0;i<random_size;i++){
value = PositionOfMemory(MEMORYTable,random[i], memorysize);
if(value>=0){
cout<<"页"<<random[i]<<"没有发生缺页"<<endl;
MEMORYTable[value].access_time = 0;
for(k=0;k<memorysize;k++)
if(k!=value)
MEMORYTable[k].access_time++;
}
else{
page_fault_time++;
value = selectMax(MEMORYTable ,memorysize);
 cout<<" 页 "<<random[i]<<" 发 生 缺 页 , 替 换"<<MEMORYTable[value].pagenumber<<"页"<<endl;
MEMORYTable[value].pagenumber = random[i];
 MEMORYTable[value].access_time = 0;
 for(l=0;l<memorysize;l++)
if(l!=value)
MEMORYTable[l].access_time++;
}
}
cout<<"缺页次数为:"<<page_fault_time;
cout<<"缺页率为:"<<(double)page_fault_time/random_size*100<<"%"<<endl;
free(MEMORYTable);
}
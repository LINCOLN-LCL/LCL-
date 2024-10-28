#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<memory.h>
#include"fifo.h"
#include"lru.h"
using namespace std;
/*随机产生数组*/
void generateArray(int *array,int size,int pagesize)
{
int temp;
srand(time(NULL));
for(int k =0;k<size;k++){
temp = rand()%pagesize;
array[k] = temp;
}
}
int main()
{
int size_random;
 int page_size;
int memory_size;
int *randomArray;
while(true){
cout<<"请输入随机访问的数组大小：";
cin>>size_random;
cout<<"请输入页表的大小:";
cin>>page_size;
cout<<"请输入内存的大小:";
cin>>memory_size;
 randomArray = (int*)malloc(sizeof(int)*size_random);
 generateArray(randomArray,size_random,page_size);
cout<<"FIFO:"<<endl;
FIFO(page_size,size_random,memory_size,randomArray);
cout<<"LRU:"<<endl;
lru(memory_size,size_random,randomArray);
 
 free(randomArray);
}
return 0;
}


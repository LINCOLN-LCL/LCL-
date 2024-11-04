#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void moni(int *CD,int CT,int n)
{
int k=0,i,sum=0,max=-1,min=-1;
int *s=(int*)malloc(sizeof(int)*n);
srand(time(NULL));
while(k!=n)
{
for(i=CT-1;i<200 && k!=n;i++)
if(CD[i])
{
s[k]=i+1;
printf("%d ",i+1);
CD[i]=0;
max=i+1;
k++;
}
for(i=CT-2;i>=0 && k!=n;i--)
if(CD[i])
{
min=i+1;
s[k]=i+1;
printf("%d ",i+1);
CD[i]=0;
k++;
}
if(min!=-1 && max!=-1)
sum=2*max-100-min;
elseif(min!=-1)
sum=100-min;
elseif(max!=-1)
sum=max-100;
}
}
int main()
{
int CD[200],CT=100,i,choice,num,tem;
for(i=0;i<200;i++)
CD[i]=0;
while(scanf("%d",&choice)!=EOF && choice)
{
scanf("%d",&num);
if(num<200 && num>0)
{
for(i=0;i<num;i++)
{
tem=rand()%200;
for(;CD[tem];tem=rand()%200);
CD[tem]=1;
}
moni(CD,CT,num);
}
else{
} 
}
return0;
}  
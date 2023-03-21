#include<stdio.h>
#include<stdlib.h>
#include<tmsort.h>
int myComparator(void *left, void *rigth)
{
int *i=(int *)left;
int *j=(int *)rigth;
return (*i)-(*j);
}
int main()
{
int *x,y,req;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d number\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
int success;
int error;
mergeSort(x,myComparator,sizeof(int),0,req-1,&success,&error);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
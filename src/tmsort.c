#include<tmsort.h>
void mergeSort(void *x, int (*p2f)(void *, void *), int es, int lowerBound, int upperBound, int *successful, int *error)
{
int a,b,mid;
struct LBUB
{
int lb,ub;
};
int success;
int errorNumber;
Stack stack1,stack2;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
initStack(&stack1,sizeof(struct LBUB),&success,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&success,&errorNumber);
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub,&success,&errorNumber);
if(!success)
{
*error=errorNumber;
clearStack(&stack1,&success,&errorNumber);
clearStack(&stack2,&success,&errorNumber);
return;
}
while(!(isEmpty(&stack1,&success,&errorNumber)))
{
pop(&stack1,(void *)&lbub,&success,&errorNumber);
push(&stack2,(void *)&lbub,&success,&errorNumber);
if(!success)
{
*error=errorNumber;
clearStack(&stack1,&success,&errorNumber);
clearStack(&stack2,&success,&errorNumber);
return;
}
a=(int)lbub.lb;
b=(int)lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&success,&errorNumber);
if(!success)
{
*error=errorNumber;
clearStack(&stack1,&success,&errorNumber);
clearStack(&stack2,&success,&errorNumber);
return;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void*)&lbub,&success,&errorNumber);
if(!success)
{
*error=errorNumber;
clearStack(&stack1,&success,&errorNumber);
clearStack(&stack2,&success,&errorNumber);
return;
}
}
}
while(!isEmpty(&stack2,&success,&errorNumber))
{
pop(&stack2,(void *)&lbub,&success,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;

merge(x,p2f,es,a,mid,mid+1,b,&success,&errorNumber);
if(!success)
{
*error=errorNumber;
clearStack(&stack1,&success,&errorNumber);
clearStack(&stack2,&success,&errorNumber);
return;
}
}
if(successful) *successful=SUCCESSFUL;
}

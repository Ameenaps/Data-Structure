#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int front=0,rear=0;
int queue[SIZE];
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt,ans;
do
{
 printf("\n 1.insert \n");
 printf("2.Delete \n");
 printf("3.Search \n");
 printf("4.Exit \n");
 printf("\n Enter your option:");
 scanf("%d",&opt);
switch(opt)
{
    case 1:
         printf("data:");
         scanf("%d",&data);
         insertq(data);
         break;
    case 2:
         printf("Deleted item %d",deleteq());
         break;
    case 3:
         printf("Item to search:");
         scanf("%d",&data);
         ans=searchq(data);
         if(ans==1)
            printf("found \n");
         else
            printf("Not found \n");
            break;
    case 4:
        exit(0);
        }
      }
while(1);
}
void insertq(int item)
{
int trear=rear;
trear=(trear+1)%SIZE;
if(trear==front)
printf("Queue is full");
else
rear=trear;
queue[rear]=item;
return;
}
int deleteq()
{
if(front==rear)
{
printf("Queue is empty \n");
exit(1);
}
else
{
front=(front+1)%SIZE;
return queue[front];
}
}
int searchq(int item)
{
int tfront;
tfront=(front+1)%SIZE;
while(tfront!=rear && queue[tfront]!=item)
tfront=(tfront+1)%SIZE;
if(queue[tfront]==item)
return 1;
else
return 0;
}
 


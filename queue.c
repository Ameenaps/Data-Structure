#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE];
int front=-1,rear=-1;
void main()
{
  void insertq(int);
  int deleteq();
  int searchq(int);
  int data,opt,tfront,ans;
do
{
  printf("\n 1.Insert \n");
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
         data=deleteq();
         printf("Deleted item %d",data);
         break;
    case 3:
         printf("Item to search:");
         scanf("%d",&data);
         ans=searchq(data);
         if(ans==1)
            printf("found\n");
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
if(rear==SIZE-1)
   printf("Queue is full\n");
  
else
  que[++rear]=item;
}
int deleteq()
{
if(front==rear)
  {
   printf("Queue is empty \n");
   exit(0);
   }
else
return que[++front];
 }
int searchq(int item)
{
  int tfront=front+1;
while(front!=rear && que[front]!=item)
     ++front;
 if(que[front]==item)
    return 1;
 else
    return 0;
}



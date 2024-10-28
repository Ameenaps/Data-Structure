#include<stdio.h>
#include<stdlib.h>

struct node
 { 
 int data;
 struct node *left;
 struct node *right;
 };
 
void main()
 {
  struct node *start=(struct node *)0; //null list
  struct node *insert(struct node *,int data);
  struct node *delete(struct node *,int data);
  struct node *search(struct node *,int data);
  void display(struct node *);
  int opt,data;
do
 {
   printf("\n 1.Insert \n 2.Delete \n 3.Search \n 4.Display \n 5.Exit \n");
   printf("Enter your option:");
   scanf("%d",&opt);
  
 switch(opt)
 {
  case 1:printf("Enter Data:");
         scanf("%d",&data);
         start=insert(start,data);
         break;
 case 2:printf("Enter data:");
        scanf("%d",&data);
        start=delete(start,data);
        break;
 case 3:printf("Enter data:");
        scanf("%d",&data);
        if(search(start,data)==(struct node *)0)
          printf("Not found\n");
        else
        printf("found\n");
        break;
case 4:display(start);
       break;
case 5:exit(0);
 }
}
while(1);
}

//to display list
void display (struct node *s)
{
 while(s!=(struct node  *)0)
 {
  printf("%d\t",s->data);
  s=s->right;
  }
}

//search an item

struct node *search(struct node *s,int data)
{
 while(s!=(struct node *)0 && s->data !=data)
 s=s->right;
 return s;
}

//to insert a node

struct node *insert(struct node *s,int data)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node *));
t->data=data;
t->left=(struct node *)0;
t->right=s;
if(s!=(struct node*)0)
{
  s->left=t;
  s=t;
  }
}
//to delete a node

struct node *delete(struct node *s,int data)
{
 struct node *t;
 t=search(s,data);
 if(t!=(struct node *)0)
 {
  if(t->left==(struct node *)0 && t->right==(struct node *)0)
  s=0;
  else if(t->left==0) //case of first node
  {
   s=s->right;
   s->left=0;
  }
else if(t->right==0)
 t->left->right=0;
else //interior node
  {
   t->left->right=t->right;
   t->right->left=t->left;
  }
 free(t);
  }
else
  printf("not found");
  return s;
}  



#include<stdio.h>
#include<stdlib.h>
#define SIZE 9
struct bit{unsigned char x:1;};                                                            
int uset[]={1,2,3,4,5,6,7,8,9};
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void interset(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[10]={0},b[10]={0},c[10]={0};
int n;
printf("number of elements in set A:");
scanf("%d",&n);
readset(a,n);
printf("number of elements in set B:");
scanf("%d",&n);
readset(b,n);

printf("\n set A:");
printset(a);
printf("\n set B:");
printset(b);
unionset(a,b,c);
printf("\n A U B=");
printset(c);
interset(a,b,c);
printf("\n A intersection B=");
printset(c);
difference(a,b,c);
printf("\n A-B=");
printset(c);
}
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<SIZE;++k)
if(a[k].x==1)
printf("%d,",uset[k]);
printf("}\n");
return;
}
void interset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
c[k].x=a[k].x & b[k].x;
return;
}
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
if(a[k].x==1)
c[k].x=a[k].x^b[k].x;
return;
}
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<SIZE;++k)
c[k].x=a[k].x | b[k].x;
return;
}
void readset(struct bit a[],int n)
{
int i,x,k;
printf("Enter %d\t elements:\n",n);
for(i=0;i<n;++i)
{
scanf("%d",&x);
for(k=0;k<SIZE;++k)
if(uset[k]==x)
{
a[k].x=1;
break;
}
}
}

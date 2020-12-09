#include<stdio.h>
#include<malloc.h>
# define isempty printf("/n empty list");
struct node
{
int value;
struct node *next;
//struct node *snode;
};
snode *createnode(int);
void insertnodefirst();
void insertnodelast();
void insertnodepos();
void deletepos();
void search();
void display();
void revdisplay(snode*);
typedef struct node snode;
snode *newnode,*ptr,*pre,*temp;
int main()
{
int ch;
char ans='y';
while(ans=='y'||ans=='y')
{
printf("\n---------------------\n");
printf("operation of linked list \n");
printf("\n 1.insert node at first");
printf(" \n2.insertnode at last");
printf("\n 3.insert node at position");
printf("\n 4.delete node at position");
printf("\n 5.search element in linked list");
printf("\n 6.display list from beginning fron end");
printf("\n 7.display list from end using recur");
printf("\n 8.exit");
printf("\n---------------------------------");
printf("enter the choice");
scanf("%d",&ch);

switch(ch)
{
case 1:
printf("\n inserting node at first");
insertnodefirst();
break;
case 2:
printf("\n inserting node at end");
insertnodelast();
break;
case 3:
printf("\n inserting node at position");
insertnodepos();
break;
case 4:
printf("\n deleting node from any position");
deletepos();
break;
case 5:
printf("\n searching element in the list");
search();
break;
case 6:
printf("\n displaying list from begning to end ");
display();
break;
case 7:
printf("displaying list from end using recusion");
revdisplay();
break;
case 8:
printf("\n exiting");
return 0;
break;
default:
printf("\n invalid");
break;
}
printf("\n you want to continue (y/n)");
scanf("%c",&ans);
}
return 0;
}
snode* create_node(int val)
{
newnode=(snode*)malloc(sizeof(snode));
if(newnode==NULL)
{
printf("\n m/y was not alloted");
return 0;
}
else
{
newnode->value=val;
newnode->next=NULL;
return newnode;
}
}
void insertnodefirst()
{
int val;
printf("\n enter the value of node");
scanf("%d",&val);
newnode=create_node(val);
if(first==last && first==NULL)
{
first=last=newnode;
first->next=NULL;
last->next=NULL;
}
else
{
temp=first;
first=newnode;
first->next=temp;
}
printf("\n inseryted");
}

void insertlast()
{
int val;
printf("\n enter the value for the node");
scanf("%d",&val);
newnode=create_node(val);
if(first==last && last==NULL)
{
first=last=newnode;
first->next=NULL;
last->next=NULL;
}
else
{
last->next=newnode;
last=newnode;
last->next=NULL;
}
printf("\n inserted");
}
void insertnodepos()
{
int pos,val,cnt=0,i;
printf("enter the value of node");
scanf("%d"&val);
newnode=create_node(val);
printf("\n enter the position");
scanf("%d",&pos);
ptr=first;
while(ptr!=NULL)
{
ptr=ptr->next;
cnt++_;
}
if (pos==1)
{
if(first==last && first ==NULL)
{
first=last=newnode;
first->next=NULL;
last->next=NULL;
}
else
{
temp=first;
first=newnode;
first->next=temp;
}
printf("\n inserted");
}
else if(pos>1 && pos<=cnt)
{
ptr=first;
for(i=1;i<pos;i++)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=newnode;
newnode->next=ptr;
printf("\n inserted");
}
else
{
printf("position is out og range");
}
}
void deletepos()
{
int pos,cnt=0,i;
if (first==NULL)
{
isempty;
printf("\n no node to deleted");
}
else
{
printf("\n enter the position of value to be deleted");
scanf("%d",&pos);
ptr=first;
if(pos==1)
{
first=ptr->next;
printf("\n element deleted");
}
else
{
while(ptr!=NULL)
{
ptr=ptr->next;
cnt=cnt+1;
}
if(pos>0 && pos<=cnt)
{
ptr=first;
for(i=1;i<pos;i++)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=ptr->next;
}
else
{
printf("position is out of range");
}
free(ptr);
printf("\n element deleted");
}
}
}
void search()
{
int flag=0,key,pos=0;
if(first==NULL)
{
isempty;
printf("\n no nodes in the list");
}
else
{
printf("enter the value of search");
scanf("%d",&key);
for(ptr=first;ptr!=NULL;ptr=ptr->next)
{
pos=pos+1;
if(ptr->value==key)
{
flag=1;
break;
}
}
if(flag==1)
{
printf("\n element %d found at %d position \n",key,pos);
}
}
}
void display()
{
if(first==NULL)
{
isempty;
printf("no nodes in the list to display");
}
else
{
for(ptr=first;ptr!=NULL;ptr=ptr->next)
{
printf("%d",ptr->value);
}
}
}
void revdisplay(snode *ptr)
{
int val;
if(ptr==NULL)
{
isempty;
printf("no nodes to display");
}
else
{
if(ptr!=NULL)
{
val=ptr->value;
revdisplay(ptr->next);
printf("%d \t",val);
}
}
}
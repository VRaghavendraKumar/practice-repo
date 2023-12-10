#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* create(int n)
{
    struct node *tail;
    tail=NULL;
    for(int i=0;i<n;i++)
    {
        struct node *newnode=malloc(sizeof(struct node));
        printf("\n enter the element %d ",i+1);
        scanf("%d",&newnode->data);
    if(tail==NULL)
    {
        tail=newnode;
        newnode->link=tail;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    }
    return tail;
}
void display(struct node *tail)
{ 
    if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else{
struct node *temp=tail->link;
printf("\nelements of the list are ");
do
{
    printf(" %d ",temp->data);
    temp=temp->link;
}while(temp!=tail->link);
    }
}
struct node* insertbeg(struct node* tail,int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==NULL)
    {
        tail=newnode;
        newnode->link=tail;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
    }
    printf("\nnode added at the beginning");
    return tail;
}
struct node* insertend(struct node* tail,int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==NULL)
    {
        tail=newnode;
        newnode->link=tail;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=tail->link;
    }
    printf("\nnode added at the end");
    return tail;
}
struct node* insertmiddle(struct node* tail,int data,int p)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
     if(tail==NULL)
    {
        tail=newnode;
        newnode->link=tail;
    }
    else if(p==1)
        {
            newnode->link=tail->link;
        tail->link=newnode;
        }
    else
    {
        struct node* temp=tail->link;
        for(int i=0;i<p-2;i++)
        {
            temp=temp->link;
        }
         if(temp==tail)
        {
         newnode->link=tail->link;
          tail->link=newnode;
          tail=tail->link;
        }
        else
        {
            newnode->link=temp->link;
            temp->link=newnode;
        }
        printf("\nnewnode added at position %d",p);
        return tail;
    }
}
struct node* deletefirst(struct node* tail)
{
     if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else
    {
    struct node *temp=tail->link;
    tail->link=temp->link;
    free(temp);
    temp=NULL;
    printf("\nfirst element is deleted");
    }
    return tail;
}
struct node* deletelast(struct node* tail)
{
    if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else if(tail->link==tail)
    {
        free(tail);
        tail=NULL;
        printf("\nfirst node is the last node"); 
    }
    else
    {
        struct node* temp=tail->link;
        while(temp->link!=tail)
        {
            temp=temp->link;
        }
        tail=temp;
        temp=temp->link;
        tail->link=temp->link;
        free(temp);
        temp=NULL;
        printf("\nlast element is deleted");
    }
    return tail;
}
struct node *deletemiddle(struct node *tail,int p)
{
    if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else if(tail->link==tail)
    {
        free(tail);
        tail=NULL;
        printf("\nfirst node is the last node"); 
    }
    else
    {
        struct node*temp1=tail->link;
        struct node*temp2=tail->link;
        if(p==1)
        {
          struct node *temp=tail->link;
          tail->link=temp->link;
          free(temp);
          temp=NULL;
          printf("\nfirst element is the deleted");
        }
        else
        {
            temp1=temp1->link;
            for(int i=0;i<p-2;i++)
            {
                temp1=temp1->link;
                temp2=temp2->link;
            }
            if(temp1==tail)
            {
                tail=temp2;
        temp2=temp2->link;
        tail->link=temp2->link;
        free(temp2);
        temp2=NULL;
        printf("\nlast element %d deleted",p);
            }
            else
            {
                temp2->link=temp1->link;
                free(temp1);
                printf("\nlast element %d deleted",p);
            }
        }
    }
    return tail;
}
void number(struct node *tail)
{
    if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else
    {
    struct node *temp=tail->link;
      int count=0;
    
    while(temp!=tail)
    {
        temp=temp->link;
        count++;
    }
    count++;
    printf("\nthe number of nodes are %d",count);
    }
}
void search(struct node *tail)
{
    int a;
    int p=1;
    int count=0;
    printf("\nenter the element to be searched ");
    scanf("%d",&a);
    if(tail==NULL)
    {
        printf("\nlist is empty broo");
    }
    else
    {
        struct node *temp=tail->link;
        do
        {
            if(a==temp->data)
            {
                printf("\n the element is found at %d",p);
                count++;
            }
            temp=temp->link;
            p++;
        } while (temp!=tail->link);
        if(count==0)
        {
            printf("\nelement is not there in the list");
        }
    }
}
int main()
{
    struct node *tail;
    tail=create(4);
    number(tail);
    display(tail);
    search(tail);
    

}
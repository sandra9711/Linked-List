# include <stdio.h>
 
# include <stdlib.h>
struct slinklist
{
 int data;
 struct slinklist *next;
};

typedef struct slinklist node;
node *head = NULL;
node *ptr,*curr,*prev,*q;
node* getnode()
{
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
     return newnode;
}
 
void traverse()
{
    node *temp;
    temp = head;
    printf("\n The contents of List : \n");
    if(head == NULL)
    {
        printf("\n Empty List\n");
        return;
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->", temp -> data);
            temp = temp -> next;
        }
    }
    printf(" NULL\n ");
}
void insertbeg()
{
    node *newnode;
    newnode = getnode();
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode -> next = head;
         head = newnode;
    }
    printf("node inserted successfully\n");
}
void insertend()
{
    node *newnode, *temp;
    newnode = getnode();
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp -> next != NULL)
            {
            temp = temp -> next;
            }
        temp -> next = newnode;
    }
    printf("node inserted successfully\n");
}
void insertchoice(int p)
{
  int i;
  node *newnode,*temp;
  newnode = getnode();
  temp = head;
  if (newnode==NULL) 
  {
    printf("Unable to allocate memory.\n");
  }
  else 
  {
    for (i=2;i<=p-1;i++) 
    {
      temp=temp->next;
      if(temp==NULL)
      {
        break;
      }
    }
    
    if(temp!=NULL) 
    {
      newnode->next=temp->next;
      temp->next=newnode;
      printf("DATA INSERTED SUCCESSFULLY\n");
    } 
    else 
    {
      printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
    }
  }
}
void deletebeg()
{
    node *temp;
    if(head == NULL)
    {
        printf("\n No nodes exist.\n");
        return ;
    }
    else
    {
        temp = head;
        head = temp -> next;
        free(temp);
        printf("\n Node deleted \n");
    }
}
void deleteend()
{
    node *temp, *prev;
    if(head == NULL)
    {
        printf("\n Empty List.\n");
        return ;
    }
    else
    {
        temp = head;
        prev = head;
        while(temp -> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
        printf("\n Node deleted \n");
     }
}
void delete_val(int data)
{
    ptr = head;
    while((ptr != NULL)&&(ptr->data != data))
    {
        prev=ptr;
        ptr=ptr->next;
    }
    curr=ptr;
    prev->next=ptr->next;
    free(curr);
}
 

void delete_pos()
{
        int i,pos;
        node *temp;
        /**struct node *temp;**/
        if(head==NULL)
        {
                printf("nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { curr=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("nPosition not Found:\n");
                                        return;
                                }
                        }
                        curr->next =ptr->next ;
                        
                        free(ptr);
                }
        }
}
int main()
{
    int n,s,p,x=0,o;
    /**printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    o=2*n;
    createlist(n);
    printf("\nData in the list \n");
    traverse();**/
    while(1){
    printf("1.Insert at beginning\t2.Insert at end\t3.Insert at desired position\n");
    printf("\t4.Delete from beginning\t5.Delete values in between\t6.Delete from end\t7.Display\t8.exit\n");
    printf("enter your choice:");
    scanf("%d",&s);
    switch(s){
        case 1:{
             
            insertbeg();
            traverse();
            break;
        }
        case 2:{
             
            insertend();
            traverse();
            break;
        }
        case 3:{
            
            printf("enter the desired position:");
            scanf("%d",&p);
            insertchoice(p);
            traverse();
            break;
        }
        case 4:{
             
            deletebeg();
            traverse();
            break;
        }
        case 5:{
            delete_pos();
            traverse();
            break;
        }
        case 6:{
            
            deleteend();
             
            break;
        }
        case 7:{
            traverse();
            break;
        }
        case 8:{
            exit(0);
        }
        default: printf("invalid choice");
    }
    
    }
    
}





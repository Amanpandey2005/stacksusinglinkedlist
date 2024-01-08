#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node* next ;
};
struct node* top = NULL;
void linkedlisttraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("element :- %d\n ", ptr-> data);
        ptr = ptr->next; 
    }
}

int isempty(struct node* top){
    if(top == NULL){
        return 1;
    }
    else
    return 0;
}

int isfull(struct node*top){
    struct node*p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL)
    {
    return 1;
    }
    else{
    return 0;
    }
}

struct node* pushstackinlinkedlist(struct node* *top, int value){
    if(isfull(*top)){
    printf("stack overflow");
    }
    else
    {
        struct node*n = (struct node*)malloc(sizeof(struct node));
        n->data = value;
        n-> next= *top;
        *top=n;
    }

}

int popstackinlinkedlist(struct node **top){
    if(isempty(*top)){
        printf("stack underflow");
    }
    else{
        struct node*n = *top;
    *top = (*top)-> next;
    int x = n-> data;
    free(n);
    return x;
    }
}

int peek(int pos){
    struct node* ptr= top;
    for ( int i = 0; i < pos-1 && ptr!= NULL; i++)
    {
        ptr = ptr-> next;
    }
    if(ptr!= NULL){
        return ptr-> data;
    }
    else{
        return -1;
    }
}

int main(){
    pushstackinlinkedlist(&top,45);
    pushstackinlinkedlist(&top,90);
    pushstackinlinkedlist(&top,56);
    pushstackinlinkedlist(&top,87);
    pushstackinlinkedlist(&top,7);
     linkedlisttraversal(top);
     for (int i = 1; i <= 5; i++)
     {
        printf("value at position %d is %d\n ", i, peek(i));
     }
     
     printf("values after popping\n");
    popstackinlinkedlist(&top);
    linkedlisttraversal(top);
}
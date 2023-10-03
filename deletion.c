#include <stdio.h>
#include <stdlib.h>

 struct node{
    int data;
    struct node * next;

 };

 void linkedlisttraversal(struct node * ptr)
 {
    while(ptr != NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
 }


 // deleting the first element from the singly linked list

 struct node * deletefirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
 }

 //deletion the element at the given index from the linked list
 struct node *deleteatindex(struct node * head,int index){
    struct node * p = head;
    struct node * q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;

    }
    p-> next = q ->next;
    free(q);
    return head;

 }

 // deletion at the end from the linked list
 struct node *deleteatlast (struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while ( q->next!= NULL)
    {
        p = p->next;
        q = q->next;

    }
    p-> next = NULL;
    free(q);
    return head;
 }




  int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head = (struct node * )malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = ( struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));


    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third ->data=8;
    third->next=fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("linked list before deletion\n");
    linkedlisttraversal(head);
   
   //head = deletefirst(head);
   //head = deleteatindex(head,2);
   head = deleteatlast(head);

   printf("linkedlist after deletion\n");
   linkedlisttraversal(head);



    return 0;

  }

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void create() {}
void del() {}
struct node
{
    int data;
    struct node *next;
};
void pushback(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct node *deleteNode(struct node *p1, int data)
{

    {
        struct node *ptr = p1;
        p1=p1->next ;
        free(ptr);
    }
    return p1;
}


bool search(struct node* head, int x)
{
    struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
void printlist(struct node *next)
{
    printf("Linked List:");
    while (next != NULL)
    {
        printf("->%d", next->data);
        next = next->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, x;
    scanf("%d", &n);
    while (n--)
    {

        scanf("%d", &x);
        pushback(&head, x);
    }
    int a;
    scanf("%d", &a);

    bool k = search(head, a);
    if (k == true)
    {
        while (head->data != a)
        {
            head = deleteNode(head, a);
        }}
    else{
     printf("Invalid Node! ");
    }
   printlist(head);
    return 0;
    printf("for(i=0;i<n;i++)");
}

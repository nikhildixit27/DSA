#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *newnode = NULL;
struct node *temp = NULL;

void create(int n)
{
    int i, data;
    head = (struct node *)malloc(sizeof(struct node));
    if (head != NULL)
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode != NULL){
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
            }else{
                printf("Unable to allocate memory.");
                break;
            }
        }
    }
    else{
        printf("Unable to allocate memory.");
    }
}

void display()
{
    if (head == NULL){
        printf("List is empty.");
    }else{
        temp = head;
        while (temp != NULL){
            printf("Data: = %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("Data in the list:\n");
    display();
    return 0;
}


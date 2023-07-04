#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll
{
    int data;
    struct single_ll *link;
}sll;

void insert_at_first(sll **head);
void insert_at_last(sll **head);
void delete_at_first(sll **head);
void delete_at_last(sll **head);
void display(sll **head);

int main()
{
    sll *head = NULL;
    int opt;
    while(1)
    {
    printf("1. Insert at first\n2. Insert at last\n3. Delete at first\n4. Delete at last\n5. Display\n6. Exit\nEnter option: ");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1: insert_at_first(&head);
        break;
        case 2: insert_at_last(&head);
        break;
        case 3: delete_at_first(&head);
        break;
        case 4: delete_at_last(&head);
        break;
        case 5: display(&head);
        break;
        case 6: exit(1);
        break;
    }
    }
    return 0;
}

void insert_at_first(sll **head)
{
    int data;
    sll *new_node = (sll *)malloc(sizeof(sll));
    printf("Enter data: ");
    scanf("%d", &data);
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new_node->data = data;
        new_node->link = NULL;
        if(*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            new_node->link = *head;
            *head = new_node;
        }
    }
}

void insert_at_last(sll **head)
{
    int data;
    sll *new_node = (sll *)malloc(sizeof(sll));
    printf("Enter data: ");
    scanf("%d", &data);
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new_node->data = data;
        new_node->link = NULL;
        if(*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            sll *temp = *head;
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new_node;
        }
    }
}

void delete_at_first(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        *head = temp->link;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void delete_at_last(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        sll *prev = NULL;
        while(temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void display(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        printf("Elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
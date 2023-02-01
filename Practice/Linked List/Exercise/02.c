// Write a program in C to create a singly linked list of n nodes and display it in reverse order

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data, int num)
{
    int x;
    struct node *current = head;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &x);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
}

void display(int num)
{
    struct node *current = head;

    while (current != NULL)
    {
        for (int i = 0; i < num; i++)
        {
            printf("Data = %d\n", current->data);
            current = current->next;
        }
    }
}

void reverseDisplay(int num)
{
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

        for (int i = 0; i < num; i++)
        {
            printf("Data = %d\n", current->data);
            head = prev;
        }
    }
}

int main()
{
    int num, data;

    printf("Input the number of nodes : ");
    scanf("%d", &num);

    insert(data, num);

    printf("\nData entered in the list :\n");
    display(num);
    printf("The list in reverse are :\n");
    reverseDisplay(num);

    return 0;
}
// Write a program in C to search an existing element in a singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int num)
{
    struct node *current = head;
    int x;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &x);
        fflush(stdin);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (current == NULL)
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

void display()
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
}

int searchElement(struct node *head, int item, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == item)
        return index;

    index++;

    return searchElement(head->next, item, index);
}

int main()
{
    int num, item, index = 0;

    printf("Enter the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);

    printf("\nData entered in the list are :\n");
    display();

    printf("\nInput the element to be searched : ");
    scanf("%d", &item);
    fflush(stdin);

    index = searchElement(head, item, 0);

    if (index == -1)
        printf("Element not found!");
    else
        printf("Element found at node %d", index + 1);

    return 0;
}
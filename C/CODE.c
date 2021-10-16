/*  Q1. Write a menu driven program to do the following on single linked list :-

        a. Reverse the linked list using change of the address (Change the link/next of each node)
        b. Reverse the list by changing the value (Use stack)*/

//------------------------ CODE ------------------------------------------[NITIN KUMAR]

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *accept()
{
    node *start = NULL, *q, *temp;
    char ch = 'Y';
    int count = 1;
    while (ch != 'N' && ch == 'Y')
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter Data in Node %d:\n", count);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            for (q = start; q->next != NULL; q = q->next);
            q->next = temp;
        }
        printf("Enter N to exit or Y to continue\n");
        scanf(" %c", &ch);
        count++;
    }
    return start;
}
void reverse_1(node **start)
{
    node *prev = NULL;
    node *current = *start;
    node *Next = NULL;
    while (current != NULL)
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    *start = prev;
}
void display_ll(node *start)
{
    node *q;
    if (start == NULL)
        printf("No Elements\n");
    else
    {
        for (q = start; q != NULL; q = q->next)
            printf("%d\n", (q->data));
    }
}
int stack[50];
int top = -1;
void reverse_2(node *start)
{
    node *q;
    q = start;
    while (q != NULL)
    {
        stack[++top] = q->data;
        q = q->next;
    }
}
void display_s(int *stack)
{
    while (top >= 0)
        printf("%d\n", stack[top--]);
}
void main()
{
    node *start = NULL;
    int choice;
    printf("0)Exit\n");
    printf("1)Reverse Using Address\n");
    printf("2)Reverse using Stack\n");
    scanf("%d", &choice);
    while (choice != 0 && choice <= 2)
    {
        switch (choice)
        {
        case 0:
            printf("Exit the Program...\n");
            break;
        case 1:
            start = accept();
            printf("\nOriginal Order\n");
            display_ll(start);
            reverse_1(&start);
            printf("\nReverse Order\n");
            display_ll(start);
            break;
        case 2:
            start = accept();
            printf("\nOriginal Order\n");
            display_ll(start);
            printf("\nReverse Order\n");
            reverse_2(start);
            display_s(stack);
            break;
        }
        printf("\n\n0)Exit\n");
        printf("1)Reverse Using Address\n");
        printf("2)Reverse using Stack\n");
        scanf("%d", &choice);
        if (choice == 0)
            printf("\n\nExit the Program.....\n\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_begin(struct node **head, int info)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = info;
    new_node->next = *head;
    *head = new_node;
}

void printLinkedList(struct node *new_node)
{
    while (new_node != NULL)
    {
        printf("%d -> ", new_node->data);
        new_node = new_node->next;
    }
    printf("NULL\n");
}

void delete_given_node(struct node **head, int x)
{
    struct node *ptr1, *ptr2;
    ptr1 = *head;
    while (ptr1 != NULL && ptr1->data != x)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    if (ptr1 != NULL && ptr1->data == x)
    {
        // if (ptr1 == *head)
        // {
        //     *head = ptr1->next;
        // }
        // else
        // {
        ptr2->next = ptr1->next;
        //}
        free(ptr1);
    }
}

int main()
{
    struct node *head = NULL;
    // Insert some elements into the linked list
    insert_begin(&head, 10);
    insert_begin(&head, 20);
    insert_begin(&head, 30);
    insert_begin(&head, 40);
    // Print the linked list
    printf("Linked List: \n");
    printLinkedList(head);
    delete_given_node(&head, 20);
    printf("Linked List after deleting 20: \n");
    printLinkedList(head);
    return 0;
}

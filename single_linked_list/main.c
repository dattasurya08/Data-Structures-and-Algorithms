#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node * init_single_linklist(struct node *head, int size, int *list)
{
    struct node *ptr = head;
    head->data = list[0];
    head->link = NULL;
    for(int i = 1; i < size; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = list[i];
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
    }
    return head;
}

struct node * insert_end(struct node *head, int d)
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

struct node * delete_end(struct node *head)
{
    
    if(head == NULL)
    {
        printf("Already empty\n");
    }
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *ptr = head;
        struct node *temp = head;
        while (ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        free(ptr);
        ptr = NULL;
    }
    return head;
}

struct node * insert_start(struct node *head, int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = head;
    head = ptr;
    return head;
}

struct node * delete_start(struct node *head)
{
    
    if(head == NULL)
    {
        printf("Already empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

struct node * insert_at_pos(struct node *head, int pos, int d)
{
    if(head == NULL)
    {
        printf("Empty linked list!\n");
    }
    else
    {
        if((pos == 0)|(pos == 1))
        {
            head = insert_start(head, d);
        }
        else if(pos == -1)
        {
            head = insert_end(head, d);
        }
        else
        {
            struct node *ptr = head;
            for(int i = 1; i < pos-1; i++)
            {
                if(ptr->link == NULL)
                {
                    printf("Position %d not available\n", pos);
                    return head;
                }
                else
                {
                    ptr = ptr->link;
                }
            }
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = d;
            temp->link = ptr->link;
            ptr->link = temp;
        }
    }
    return head;
}

struct node * delete_at_pos(struct node * head, int pos)
{
    if(head == NULL)
    {
        printf("Empty linked list!\n");
    }
    else
    {
        if((pos == 0)|(pos == 1))
        {
            head = delete_start(head);
        }
        else if(pos == -1)
        {
            head = delete_end(head);
        }
        else
        {
            struct node * ptr = head;
            for(int i = 1; i < pos-1; i++)
            {
                if(ptr->link == NULL)
                {
                    printf("List index out of range\n");
                    return head;
                }
                else
                {
                    ptr = ptr->link;
                }
            }
            struct node *temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            temp = NULL;
        }
    }
    return head;
}

void print_single_linklist(struct node *head)
{
    struct node *ptr = head;
    printf("Linked list elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int init_list[3] = {15, 30, 45};
    init_single_linklist(head, 3, init_list);
    printf("Initially              > ");
    print_single_linklist(head);
    head = insert_start(head, 5);
    printf("Adding 5 at beginning  > ");
    print_single_linklist(head);
    head = delete_end(head);
    printf("Deleting last element  > ");
    print_single_linklist(head);
    head = insert_at_pos(head, 3, 50);
    printf("Adding 50 at pos #3    > ");
    print_single_linklist(head);
    head = delete_at_pos(head, 4);
    printf("Deleting element 4     > ");
    print_single_linklist(head);
    head = insert_end(head, 80);
    printf("Adding 80 at the end   > ");
    print_single_linklist(head);
    return 0;
}

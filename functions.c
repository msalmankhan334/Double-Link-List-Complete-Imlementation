#include <stdio.h>
#include <stdlib.h>
#include "funcheader.h"

int getValue(char *str) {
    printf("%s", str);
    int value;
    scanf("%d", &value);
    return value;
}
void printList(Node **head) {
    Node *p;
    p = *head;
    if(p == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("%p <--> ", p->left);
    while(p != NULL) {
        printf("%d <-->", p->number);
        p = p->right;
    }
    printf(" %p \n", p);
}    
int Listlength(Node **head) {
    Node *p;
    p = *head;
    int count = 0;
    while(p != NULL) {
        count++;
        p = p->right;
    }
    return count;
}
Node *createDlist(Node *head ,int size) {
    Node *temp,*p;
    for (int i = 0; i < size; i++)
    {
        if(head == NULL) {
            temp = (Node *)malloc(sizeof(Node));
            if(temp == NULL) {
                printf("Error in Allocating Memory\n");
                exit(0);
            }
            temp->left = NULL;
            temp->number = getValue("Enter the Number: ");
            temp->right = NULL;
            head = temp;
        }
        else {
            p = head;
            while(p->right !=NULL) {
                p = p->right;
            }
            temp = (Node *)malloc(sizeof(Node));
            if(temp == NULL) {
                printf("Error in Allocating Memory\n");
                exit(0);
            }
            temp->number = getValue("Enter the Number: ");
            temp->left = p;
            temp->right = NULL;
            p->right = temp;
        }
    }
    return head;
}
void insertAtStart(Node **head) {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Error in Allocating Memory\n");
        exit(0);
    }
    temp->number = getValue("Enter New Number: ");
    temp->right = *head;
    temp->left = NULL;
    *head = temp;
}
void insertAtEnd(Node **head) {
    Node *temp,*tp;
    tp = *head;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Error in Allocating Memory\n");
        exit(0);
    }
    while (tp ->right != NULL) {
        tp = tp->right;
    }
    temp->number = getValue("Enter New Number: ");
    temp->right = NULL;
    temp->left = tp;
    tp->right = temp;
}
void inserNodeAtPosition(Node **head, int pos) {
    Node *temp, *p, *q;
    int k = 1;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Error in Allocating Memory\n");
        exit(0);
    }
    if(pos == 1) {
        insertAtStart(head);
    }else if(pos >= Listlength(head)) {
        insertAtEnd(head);
    }else
    {
        q = *head;
        while(k < pos) {
            k++;
            p = q;
            q = q->right;
        }
        temp->number = getValue("Enter New Number: ");
        temp->right = q;
        q->left = temp;
        temp->left = p;
        p->right = temp;
    }
}
void deleteNodeFrmStrt(Node **head) {
    Node *temp;
    temp = *head;
    *head = (*head)->right;
    (*head)->left = NULL;
    free(temp);
}
void deleteNodeFrmEnd(Node **head) {
    Node *p, *q;
    q = *head;
    while( q->right != NULL) {
        p = q;
        q = q->right;
    }
    p->right = NULL;
    free(q);
}
void deleteNodeAtPos(Node **head, int pos) {
    Node *p, *q,*r;
    q = *head;
    int k = 1;
    if(pos == 1) {
        deleteNodeFrmStrt(head);
    }else if(pos >= Listlength(head)) {
        deleteNodeFrmEnd(head);
    }else
    {
        while(k<pos) {
            p = q;
            q = q->right;
            r = q->right;
            k++;
        }
        p->right = r;
        r->left = p;
        free(q);
        return;
    }
    
}
#include <stdio.h>
#include "funcheader.h"


int main() {
    Node *Head = NULL;
    int size = getValue("Enter the Size of Double List to Create: ");
    Head = createDlist(Head, size);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    printf("Enter Node At the Begining: ");
    insertAtStart(&Head);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    printf("Enter Node At the End: ");
    insertAtEnd(&Head);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    int pos = getValue("Enter The Position To Insert the Node: ");
    inserNodeAtPosition(&Head, pos);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    printf("Node is Deleted from the Start\n");
    deleteNodeFrmStrt(&Head);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    printf("Node is Deleted from the Last\n");
    deleteNodeFrmEnd(&Head);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    pos = getValue("Enter the Position Node to Delete: ");
    deleteNodeAtPos(&Head, pos);
    printList(&Head);
    printf("The Length of List is %d: \n", Listlength(&Head));
    return 0;
}
typedef struct Node
{
    int number;
    struct Node *left;
    struct Node *right;
}Node;
void printList(struct Node **head);
int getValue(char *str);
int Listlength(Node **head);
Node *createDlist(Node *head, int size);
void insertAtStart(Node **head);
void insertAtEnd(Node **head);
void inserNodeAtPosition(Node **head, int pos);
void deleteNodeFrmStrt(Node **head);
void deleteNodeFrmEnd(Node **head);
void deleteNodeAtPos(Node **head, int pos);
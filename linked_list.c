#include <stdio.h>
#include <stdlib.h>

#define MENU_ADD 1
#define MENU_REMOVE 2
#define MENU_INSERT 3
#define MENU_PRINT 4
#define MENU_QUIT 5

typedef struct Node Node;

struct Node{
    int data;
    Node *next;
};

Node* head = NULL;

int safeReadInt(int *value)
{
    if (scanf("%d", value) != 1)
    {
        while (getchar() != '\n')
            ; // Clear input buffer
        printf("Invalid input. Please enter a number.\n");
        return 0;
    }
    return 1;
}

/**
 * Prints the contents of the linked list.
 * Iterates through the list, printing each node's data value separated by an arrow (->) and ends with "NULL".
 */
void printList(){
    Node* current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return;
}

/**
 * Adds a new node with the given data to the beginning of the linked list.
 *
 * If the list is empty, the new node becomes the head of the list.
 * Otherwise, the new node is inserted at the beginning of the list, with its
 * next pointer pointing to the current head.
 *
 * @param data The data to be stored in the new node.
 * @return The newly created node, or NULL if memory allocation failed.
 */
Node *addNode(int data){
    Node* newNode = NULL;

    if(head == NULL){
        newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Error: malloc failed.\n");
            return NULL;
        }

        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Error: malloc failed.\n");
            return NULL;
        }

        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    return newNode;
}

void printMenu()
{
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list.\n");
    printf("\t2. Remove a node from the list.\n");
    printf("\t3. Insert a node to the list.\n");
    printf("\t4. Print your list\n");
    printf("\t5. Quit.\n");
    return;
}

/**
 * Removes a node with the given data from the linked list.
 *
 * @param data The data value of the node to be removed.
 * @return 1 if the node was successfully removed, 0 if the node was not found.
 */
int removeNode(int data){
    Node* current = head;
    Node* previous = head;

    while(current != NULL){

        if(current->data == data){
            if(current == head){
                Node *new_head = head->next;
                free(head);
                head = new_head;
            }
            else{
                previous->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        }
        previous = current;
        current = current->next;
    }
    printf("Error: Node not found.\n");
    return 0;
}


/**
 * Inserts a new node with the given data at the specified position in the linked list.
 *
 * @param data The data to be stored in the new node.
 * @param position The position at which the new node should be inserted (0-based index).
 * @return The newly inserted node, or NULL if the operation failed.
 */
Node *insertNode(int data, int position){
    // Handle special case for empty list
    if (head == NULL) {
        return addNode(data);
    }
    
    // Handle insertion at beginning (position 0)
    if (position == 0) {
        return addNode(data);
    }

    Node *current = head;
    int currentPos = 0;
    
    // Move to position - 1
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Error: position out of bounds.\n");
        return NULL;
    }

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: malloc failed.\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    return newNode;
}
    
int main(int argc, char** argv)
{
    int option = -1;
    int arg1 = 0 ;
    int arg2 = 0;
    Node *new_node = NULL;
    while (option != 5)
    {
        printMenu();
        if (safeReadInt(&option)) {
            if (option > 0 && option <= 5) {
                switch(option) {
                    case MENU_ADD:
                        // add a node to the list
                        printf("Enter the data you want to add to the list: ");
                        if (safeReadInt(&arg1)) {
                            new_node = addNode(arg1);
                        }
                        break;
                    case MENU_REMOVE:
                        // remove a node from the list
                        printf("Enter the data you want to remove from the list: ");
                        if (safeReadInt(&arg1)) {
                            int sucsses = removeNode(arg1);
                            if(!sucsses) {
                                printf("The node you are trying to remove does not exist in the list.\n");
                            }
                        }
                        break;
                    case MENU_INSERT:
                        // insert a node to the list
                        printf("Enter the data you want to insert to the list: ");
                        if (safeReadInt(&arg1)) {
                            printf("Enter the location you want to insert the node to: ");
                            if (safeReadInt(&arg2)) {
                                new_node = insertNode(arg1, arg2);
                                if (new_node == NULL) {
                                    printf("Failed to insert into list\n");
                                }
                            }
                        }
                        break;
                    case MENU_PRINT:
                        // print the list
                        printList();
                        break;
                    case MENU_QUIT:
                        break;
                }
            }
        }
    }
    while (head != NULL)
    {
        Node *new_head = head->next;
        free(head);
        head = new_head;
    }
    return 0;
}



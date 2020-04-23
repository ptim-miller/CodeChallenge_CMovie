// All rights reserved (c) 2020 P. Tim Miller
// For academic use only
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node *next;
} Node;

typedef Node *NodePtr;
NodePtr start;

void printNodes(NodePtr nPtr);
void printMessage(NodePtr nPtr);
int getChoice();
int getSelection();
NodePtr positionPtr(int selected);
void insertNode(NodePtr nPtr);
void editNode(NodePtr nPtr);

/*
* Author <student name>
*   Clue1: "Quote from this movie
*   where Caesar is the key, not the star."
*
*   Clue2: "Arguably his fourth wife, Calpurnia
*   stood to the right of Caesar until his death."
*
*   Clue3: "Conspirators employed clever arguments to convince
*   Caesar to reverse his decisions."
*
*   Finish items in the code according to instructions.
*   Translate the linked list values upon completion
*   and answer the questions if you can:
*   What is the quote?  __________________________________________
*   What is the movie?  __________________________________________
*   Either of two movies are acceptable answers.
*
*/
int main(){
    int values[] = {11,105,111,101,120,120,115,114,116,101,105,112,101,99,
                    105,111,114,105,104,104,109,108,69,114,115,109,120,101,
                    105,118,103,114,97,115,119,109,108,119,105,120,101,108,
                    115,108,97,118,115,120,101,105,118,103,32,32,11};
    int arrLen= sizeof(values)/sizeof(values[0]);
    NodePtr current;

    start = malloc( sizeof(Node) );
    // TODO - add stuff here to verify malloc
    start->next = 0;
    current = start;

    for(int i = 0; i < arrLen; ++i){
        current->next = 0;
        current->v = values[i];
        if(i+1 != arrLen){
            current->next = malloc(sizeof(Node));
            // TODO - add stuff here to verify malloc
            current = current->next;
        }
    }

    int selected = -1;
    int choice = -1;

    // CRUD operations
    while( (choice = getChoice()) != 0){
        current = start;
        switch (choice) {
            case 1:
                printf("New node will be added after selected node.\n");
                // TODO - let user select node
                // TODO - set selection to current
                // TODO - check if current selection is valid
                // TODO - if so, insert a new node
                break;
            case 2:
                printNodes(current);
                printf("\n");
                break;
            case 3:
                // TODO - let user select node
                // TODO - set selection to current
                // TODO - check if current selection is valid
                // TODO - if so, edit selected node
                break;
            case 4:
                printf("Selected node will be deleted.\n");
                // TODO - add code here to delete
                break;
//            case 5: //Prints secret message (after all changes from instructions)
//                printMessage(current);
//                printf("\n");
//                break;
            default :
                printf("Invalid selection\n");
                break;
        }
    }
    return 0;
}

void printNodes(NodePtr nPtr){
    system("clear");
    int count = 1;
    printf("#   v      Node        Next\n");
    while(nPtr != 0){
        printf("%d:  %03d    %p    %p \n", count++, nPtr->v,  nPtr, nPtr->next);
        nPtr = nPtr->next;
    }
}

void printMessage(NodePtr nPtr){
    system("clear");
    while(nPtr != 0){
        printf("%03d ", nPtr->v);
        nPtr = nPtr->next;
    }
}

int getChoice(){
    int choice = -1;
    char enter;
    printf("1 to Insert a Node | ");
    printf("2 to Print Nodes | ");
    printf("3 to Edit a Node | ");
    printf("4 to Delete a Node | ");
//    printf("5 Secret Message | ");
    printf("0 to Exit \n");
    scanf("%d%c", &choice, &enter);
    return choice;
}

int getSelection(){
    int choice = -1;
    char enter;
    printf("Please select a node number.\n");
    scanf("%d%c", &choice, &enter);

    return choice;
}

// RETURNS 0 if invalid selection
NodePtr positionPtr(int selected){
    NodePtr nPtr = start;
    if(selected > 0){
        for(int i = 1; i <= selected; ++i){
            if(i == selected){
                return nPtr;
            } else {
                if(nPtr->next != 0){
                    nPtr = nPtr->next;
                } else {
                    printf("Node %d is invalid.\n", selected);
                    return nPtr->next;
                }
            }
        }
    }
    return 0;
}

// Inserts new node after nPtr
void insertNode(NodePtr nPtr){
    // TODO - add stuff here
}

// Modifies node based on user input
void editNode(NodePtr nPtr){
    int newValue = -1;
    char enter;
    printf("Selected node value is: %d.\nPlease enter an new value.\n", nPtr->v);
    scanf("%d%c", &newValue, &enter);
    nPtr->v = newValue;
    printf("Node value is now: %d.\n", nPtr->v);
}

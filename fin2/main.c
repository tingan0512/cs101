#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    char data;
    struct LinkedList *next;
} LinkedList;

LinkedList* allocNode(int data){
    LinkedList* new = (LinkedList*)malloc(sizeof(LinkedList*));
    new -> data = data;
    new -> next = NULL;
    
    return new;
}

void showList(LinkedList* list){
    while(list != NULL){
        printf("[%c]->",list->data);
        list = list -> next;
    }
    printf("null\n");
}

LinkedList* appendList(LinkedList* list, char new_data){
    LinkedList* at = list;
    LinkedList* pre = NULL;
    LinkedList* new = allocNode(new_data);

    while (at!=NULL) {
        pre = at;
        at = at -> next;
    }

    if (pre!=NULL) {
        pre -> next = new;
    } else {
        list = new;
    }
    
    return list;
}

LinkedList* reverseList(LinkedList* list) {
    LinkedList* prev = NULL;
    LinkedList* current = list;
    LinkedList* next = NULL;
  
    while (current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(){
    LinkedList* head = NULL;
    head = appendList(head,'A');
    head = appendList(head,'B');
    head = appendList(head,'C');
    head = appendList(head,'D');
    head = appendList(head,'E');
    showList(head); 
    head = reverseList(head);
    showList(head); 
    
    return 0;
}

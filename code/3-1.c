#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[10];
    int score;
    struct Node* next;
};

struct Node* head = NULL;


void add(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

void delete(char * name) {
    struct Node* p = head;
    if (strcmp(p->name, name) == 0)
    {
        head = p->next;
        free(p);
        return;
    }

    struct Node* prev;
    while (p != NULL && strcmp(p->name, name) != 0) {
        prev = p;
        p = p->next;
    }

    prev->next = p->next;
    free(p);
}

void print() {
    struct Node* p = head;
    while (p != NULL) {
        printf("%s %d\n", p->name, p->score);
        p = p->next;
    }
}

void quit() {
    struct Node* p = head;
    while (p != NULL) {
        struct Node* temp = p->next;
        free(p);
        p = temp;
    }
}

int main() {
    char a[20];
    char name[10];
    int score;

    while (1) {
        
        scanf("%s", a);

        if (strcmp(a, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } 
        else if (strcmp(a, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } 
        else if (strcmp(a, "print") == 0) {
            print();
        } 
        else if (strcmp(a, "quit") == 0) {
            quit();
            break;    
        }
    }

    return 0;
}

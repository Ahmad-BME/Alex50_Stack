#include <stdio.h>
#include <stdlib.h>

struct node {
            int data;
            struct node *pNext;
}*pTop;

void push(int data);
int pop();
int peek();
void printAll();


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printAll();

    printf("The last data = %d\n\n", peek());
    printAll();




    return 0;
}

void push(int data) {


        struct node *pNode = (struct node*)malloc(sizeof(struct node));
        struct node *pCur = pTop;

        if (pNode != NULL) {

                pNode -> pNext = pTop;
                pNode -> data = data;
                pTop = pNode;
        }
        else {
            printf("\n\nNot enough space.\n");
        }
}

int pop() {

    int value = 0;
    if (pTop != NULL) {
        struct node *pCur = pTop;
        value = pTop -> data;
        pTop = pTop -> pNext;
        free(pCur);
    }
    else {
        printf("\nStack is Empty!!!\n");
    }
    return value;
}

int peek() {
    if (pTop != NULL) {
        return pTop -> data;
    }
    else {
        printf("\nStack is Empty!!!\n");
        return 0;
    }

}

void printAll() {
    struct node *pCur;
    for (pCur = pTop; pCur != NULL; pCur = pCur -> pNext ){
        printf("%d\n", pCur -> data);
    }
    printf("\n");
    return;
}

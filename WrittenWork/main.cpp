//
//  main.cpp
//  WrittenWork
//
//  Created by shaked chen on 29/01/2022.
//

#include <iostream>
#define LAST_INDEX -1
#define NEED_TO_CHECK_LAST -2

struct node {
    int data;
    struct node * next;
} ;
typedef struct node node;
void selectionSort(int A[], int n);
void recSelectionSort(int *p, int n);
int canWin(int N);
int Lakes(int* bar, int m);


void printBack(node* head);
node * reverse(node* head);

int main(int argc, const char * argv[]) {
    /**
     int i = 0;
     node s;
     s.data = 0;
     node * pre = &s;
     node * startEdg = &s;
     for (; i < 10; i++) {
         // startEdg = pre;
         node *tempNode = (node*) malloc (sizeof(node) );
         tempNode->data = i + 1;
         startEdg->next = tempNode;
         startEdg = startEdg->next;
     }
     startEdg->next = NULL;
     node * reversed = reverse(pre);
     node * next = reversed;
     // node * next = pre;
     while (next != NULL) {
         printf("value is = = > %d \n", next->data);
         next = next->next;
     }
     printf("\n PRINT BACK \n");
     printBack(reversed);
     */
    int i = 1;
    for (; i< 11; i++) printf("num ==> %d  can win == %d\n", i, canWin(i));
    /*
     std::cout << "Hello, World!\n";
     int array[] = {1,3,2,4,1,3,1,4,5,2,2,1,4,2,2,-1};
     int total = Lakes(array + 1, -2);
     printf("total of array is -- %d \n", total);
     int array[8] = {2,100,1,2,-7,4,3, 500};
     recSelectionSort(array, 8);
     int i = 0;
     for (; i < 8; i++) {
         printf("array %d \n", array[i]);
     }
     */
    return 0;
}



void selectionSort(int A[], int n) {
    int startIndex = 0;
    for (; startIndex < n ; startIndex++) {
        int arrayIndexInIter = startIndex + 1;
        // getting the current min value
        int minValue = A[startIndex];
        int minIndex = startIndex;
        for (; arrayIndexInIter < n; arrayIndexInIter++) {
            // start the sorting of the array
            int currentValue = A[arrayIndexInIter];
            if (minValue > currentValue) {
                // change the indexes to match and the values
                minValue = currentValue;
                minIndex = arrayIndexInIter;
            }
        }
        // setting the current index that we get for the current interation
        int tempValue = A[startIndex];
        A[minIndex] = tempValue;
        A[startIndex] = minValue;
    }
}
void recSelectionSort(int *p, int n) {
    // code steps
    // check in n is bigger than 1 and start
    if (n > 1) {
        int *minPointer = p;
        // loop over the array and switch between the function
        int i = 1;
        for (; i < n; i++) {
            int iterValue = *(p + i); // [5 , 50]
            // minPointer = *minPointer > iterValue ? minPointer = p + i : minPointer;
            if (*minPointer > iterValue) minPointer = p + i;
        }
        // switch between value
        int tempValue = p[0];
        p[0] = *minPointer;
        *minPointer = tempValue;
        // go to next value rec
        recSelectionSort(p + 1, n - 1);
    }
}
int canWin(int N) {
    if (N < 5 ) return !(N == 4);
    return canWin(N - 4);
}
int Lakes(int* bar, int m) {
    if (*bar == LAST_INDEX) return 0;
    // at the start m is zero to indicate anount max heightIndex;
    if (*(bar + m + 1) == LAST_INDEX) {
        // calulate backward
        int tallestIndex = 1;
        int i = 2;
        for (;i < m + 1; i ++ ) {
            int currentValue = *(bar + i);
            if ( *(bar + tallestIndex) < currentValue) tallestIndex = i;
        }
        if (tallestIndex == 1) {
            // start calculate from here and find the next biggest index
            return Lakes(bar + 1, 0);
        }
        else {
            // calcuate the water valuem
            int heightAtMaxIndex = *( bar + tallestIndex);
            int index = 1, total = 0;
            for (; index < tallestIndex + 1; index++) {
                total += heightAtMaxIndex - bar[index];
            }
            return total + Lakes(bar + tallestIndex, 0);
        }
        // I will cal until i  will find the tallest index
    }
    if (m == NEED_TO_CHECK_LAST) {
        // check the first index is is less than this
        int lastIndexHeight = *(bar - 1);
        if (lastIndexHeight > *bar) return Lakes(bar - 1, 0);
        m = 0;
    }
    int nextHeight = *(bar + m + 1);
    int height = *(bar);
    if (height > nextHeight) return Lakes(bar, m + 1);
    if (nextHeight >= *bar) {
        // need to calculate the total width until here,, if m is one start the interation from the next one
        if (m == 0) return Lakes(bar + 1, 0);
        // else calulate the value from and to
        // calc height diffrent
        int i = 1, totalHeight = 0;
        for (; i < m + 1; i++) totalHeight +=  *bar - *(bar + i);
        return totalHeight + Lakes(bar + m + 1, 0);
    }
    return 0;
}

void printBack(node* head) {
    if (head->next == NULL) {
        printf("%d \n", head->data);
    } else {
        printBack(head->next);
        printf("%d \n", head->data);
    }
}
node * reverse(node* head) {
    static node * prev = NULL;
    if (head->next == NULL) {
        head->next = prev;
        return head;
    }
    else {
        // take the next two
        node * currentHead = head;
        node * n1 =head->next;
        int isExsits = n1->next != NULL;
        node * n2 = isExsits ? n1->next : NULL;
        // switch between the two current
        head->next = prev;
        n1->next = currentHead;
        prev = n1;
        // call the function agine
        return reverse(n2);
    }
}









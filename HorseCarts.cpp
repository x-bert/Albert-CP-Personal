#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Treasure;

typedef struct {
    Treasure *data;
    int size;
    int capacity;
} PriorityQueue;


int cmpTreasure(const void *a, const void *b) {
    Treasure *x = (Treasure *)a;
    Treasure *y = (Treasure *)b;
    return x->weight - y->weight;  
}

int cmpInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); 
}


void initPQ(PriorityQueue *pq, int cap) {
    pq->data = (Treasure *)malloc(sizeof(Treasure) * (cap + 1));
    pq->size = 0;
    pq->capacity = cap;
}

void push(PriorityQueue *pq, Treasure t) {
    int i = ++pq->size;
    while (i > 1 && pq->data[i/2].value < t.value) {
        pq->data[i] = pq->data[i/2];
        i /= 2;
    }
    pq->data[i] = t;
}

Treasure top(PriorityQueue *pq) {
    return pq->data[1];
}

void pop(PriorityQueue *pq) {
    Treasure last = pq->data[pq->size--];
    int i = 1, child;
    while (i * 2 <= pq->size) {
        child = i * 2;
        if (child < pq->size && pq->data[child].value < pq->data[child+1].value)
            child++;
        if (last.value >= pq->data[child].value) break;
        pq->data[i] = pq->data[child];
        i = child;
    }
    pq->data[i] = last;
}

int empty(PriorityQueue *pq) {
    return pq->size == 0;
}


int main() {
    int A, B; 
    scanf("%d %d", &A, &B);

    Treasure *treasures = (Treasure *)malloc(sizeof(Treasure) * A);
    for (int i = 0; i < A; i++) {
        scanf("%d %d", &treasures[i].weight, &treasures[i].value);
    }

    int *carts = (int *)malloc(sizeof(int) * B);
    for (int i = 0; i < B; i++) {
        scanf("%d", &carts[i]);
    }

    
    qsort(treasures, A, sizeof(Treasure), cmpTreasure);
    qsort(carts, B, sizeof(int), cmpInt);

    PriorityQueue pq;
    initPQ(&pq, A);

    long long total = 0;
    int idx = 0;

    for (int i = 0; i < B; i++) {
        while (idx < A && treasures[idx].weight <= carts[i]) {
            push(&pq, treasures[idx]);
            idx++;
        }
        if (!empty(&pq)) {
            total += top(&pq).value;
            pop(&pq);
        }
    }

    printf("%lld\n", total);

    free(treasures);
    free(carts);
    free(pq.data);

    return 0;
}

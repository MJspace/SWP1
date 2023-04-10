#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;
}QueueType;

void init(QueueType* Q)
{
    Q->front = Q->rear = -1;
}

int isFull(QueueType* Q)
{
    return Q->front == (Q->rear + 1) % N; //원형큐에서 인덱스 움직일 땐 꼭 나머지를 이용해서!
}

int isEmpty(QueueType* Q)
{
    return Q->front == Q->rear;
}
void addFront(QueueType* Q, element e)
{

}


void addrear(QueueType* Q, element e)
{
    if (isFull(Q))
        printf("Full\n");
    else
    {

        Q->rear = (Q->rear + 1) % N;
        Q->data[Q->rear] = e;

    }
}

element peek(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("Empty\n");
        return 0;//의미 없는 값
    }

    return Q->data[(Q->front + 1) % N];
}

element deletefront(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("Empty\n");
        return 0;//의미 없는 값
    }
    Q->front = (Q->front + 1) % N;
    return Q->data[Q->front];
}


void print(QueueType* Q)
{
    printf("Front:%d-Rear:%d\n", Q->front, Q->rear);
    int i = Q->front;

    while (i != Q->rear)
    {
        i = (i + 1) % N;
        printf("[%c]", Q->data[i]);
    }

    printf("\n");

}
int main()
{
    QueueType Q;
    init(&Q);
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
        addrear(&Q, rand() % 26 + 65); //알파벳 대문자 A-Z
    print(&Q);    getchar();


    for (int i = 0; i < 4; i++)
        printf("[%c]", deletefront(&Q));
    printf("\n\n"); print(&Q);    getchar();

    for (int i = 0; i < 6; i++)
        addrear(&Q, rand() % 26 + 65); //알파벳 대문자 A-Z
    print(&Q);


    return 0;

}

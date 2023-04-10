#include <stdio.h>
#include <stdlib.h>


#define N 100

typedef struct /*이름이 안 나왔다 -> 연결된 건 아니구나*/
{
    char data[N];
    int top;
}StackType; /*~Type꼴이면 이게 최종, 노드나 다른 거 나오면 그건 타입을 만들기 위한 재료*/

void init(StackType* S) /*S의 주소가 날라와*/
{
    S->top = -1;/*S의 주소에 가봐 그러면 top이 있어*/
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == N - 1; /*99면 꽉 채웠단 얘기*/
}

void push(StackType* S, char c)
{
    if (isFull(S))
        printf("Full\]n");
    else
    {
        S->top++;/*top=0이 되고 c를 data에 넣음?*/
        S->data[S->top] = c;
    }
}

char pop(StackType* S)
{
    if (isEmpty(S)) /*에러 체크/ &S할 필요 없어 S는 이미 주소임*/
    {
        printf("Empty\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType *S)
{
    if (isEmpty(S)) /*에러 체크/ &S할 필요 없어 S는 이미 주소임*/
    {
        printf("Empty\n");
        return -1;
    }

    return S->data[S->top];
}

void print(StackType* S)
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int main()
{
    StackType S;
    init(&S); /*주소 계산해서 전달*/

    push(&S, 'C'); push(&S, 'a'); push(&S, 't'); push(&S, 's');
    print(&S);

    printf("pop : %c\n", pop(&S));
    print(&S);

    printf("peek : %c\n", peek(&S));
    print(&S);
    return 0;
}
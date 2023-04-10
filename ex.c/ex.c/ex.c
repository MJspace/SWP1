#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

typedef struct //구조체
{
    char data[N];
    int top;
} StackType;

void init(StackType* S) //초기화
{
    S->top = -1;
}

int isEmpty(StackType* S) //스택 비었을 때 
{
    return (S->top == -1);
}

int isFull(StackType* S) //스택 다 찼을 때
{
    return S->top == N - 1;
}

void push(StackType* S, char c)
{
    if (isFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType* S)
{
    if (isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType* S)
{
    if (isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }

    return S->data[S->top];
}
int main() {
    StackType S;
    char str[N];
    char rev_str[N];
    int i, len;

    scanf("%[^\n]s", str);  //공백까지 받기
    len = strlen(str);


    init(&S);

    for (i = 0; i < len; i++)
    {
        if (65 <= str[i] && 90 >= str[i]) //대문자이면 소문자로 변환
            push(&S, str[i] + 32);
    }

    for (i = 0; i < len; i++) // 문자열을 뒤집어서 rev_str에 저장
        rev_str[i] = pop(&S);


    for (i = 0; i < len; i++)
    {
        if (str[i] != rev_str[i])
        {
            printf("회문이 아닙니다.\n");
            return 0;
        }

    }

    printf("회문입니다.");

    return 0;
}
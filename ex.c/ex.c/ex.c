#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

typedef struct //����ü
{
    char data[N];
    int top;
} StackType;

void init(StackType* S) //�ʱ�ȭ
{
    S->top = -1;
}

int isEmpty(StackType* S) //���� ����� �� 
{
    return (S->top == -1);
}

int isFull(StackType* S) //���� �� á�� ��
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

    scanf("%[^\n]s", str);  //������� �ޱ�
    len = strlen(str);


    init(&S);

    for (i = 0; i < len; i++)
    {
        if (65 <= str[i] && 90 >= str[i]) //�빮���̸� �ҹ��ڷ� ��ȯ
            push(&S, str[i] + 32);
    }

    for (i = 0; i < len; i++) // ���ڿ��� ����� rev_str�� ����
        rev_str[i] = pop(&S);


    for (i = 0; i < len; i++)
    {
        if (str[i] != rev_str[i])
        {
            printf("ȸ���� �ƴմϴ�.\n");
            return 0;
        }

    }

    printf("ȸ���Դϴ�.");

    return 0;
}
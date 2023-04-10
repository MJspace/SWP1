#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 100

typedef struct /*�̸��� �� ���Դ� -> ����� �� �ƴϱ���*/
{
    char data[N];
    int top;
}StackType; /*~Type���̸� �̰� ����, ��峪 �ٸ� �� ������ �װ� Ÿ���� ����� ���� ���*/

void init(StackType *S) /*S�� �ּҰ� �����*/
{
    S->top = -1;/*S�� �ּҿ� ���� �׷��� top�� �־�*/
}

int isEmpty(StackType *S)
{
    return S->top == -1;
}

int isFull(StackType *S)
{
    return S->top == N - 1; /*99�� �� ä���� ���*/
}

void push(StackType *S, char c)
{
    if (isFull(S))
        printf("Full\n");
    else
    {
        S->top++;/*top=0�� �ǰ� c�� data�� ����?*/
        S->data[S->top] = c;
    }
}

char pop(StackType *S)
{
    if (isEmpty(S)) /*���� üũ/ &S�� �ʿ� ���� S�� �̹� �ּ���*/
    {
        printf("Empty\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType* S)
{
    if (isEmpty(S)) /*���� üũ/ &S�� �ʿ� ���� S�� �̹� �ּ���*/
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

int check(StackType *S, char str[])
{
    //StackType S;
    //init(&S);

    char c, t;
    int n = strlen(str); /*str ���ڿ� ���� ����*/
    
    for (int i = 0; i < n; i++)
    {
        c = str[i];

        if (c == '(' || c == '{' || c == '[')
            push(S, c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (isEmpty(S))
                return 0;
            else
            {
                t = pop(S);
                if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']'))
                    return 0;
            }
        }
    }
    return isEmpty(S);

}

int main()
{

    StackType S;
    init(&S);
    char str[N];
    scanf_s("%s", str);

    if (check(&S, str))
        printf("OK");
    else
        printf("NO");
    return 0;
}
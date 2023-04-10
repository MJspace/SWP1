#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 100

typedef struct /*이름이 안 나왔다 -> 연결된 건 아니구나*/
{
    char data[N];
    int top;
}StackType; /*~Type꼴이면 이게 최종, 노드나 다른 거 나오면 그건 타입을 만들기 위한 재료*/

void init(StackType *S) /*S의 주소가 날라와*/
{
    S->top = -1;/*S의 주소에 가봐 그러면 top이 있어*/
}

int isEmpty(StackType *S)
{
    return S->top == -1;
}

int isFull(StackType *S)
{
    return S->top == N - 1; /*99면 꽉 채웠단 얘기*/
}

void push(StackType *S, char c)
{
    if (isFull(S))
        printf("Full\n");
    else
    {
        S->top++;/*top=0이 되고 c를 data에 넣음?*/
        S->data[S->top] = c;
    }
}

char pop(StackType *S)
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

char peek(StackType* S)
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

int check(StackType *S, char str[])
{
    //StackType S;
    //init(&S);

    char c, t;
    int n = strlen(str); /*str 문자열 길이 읽음*/
    
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
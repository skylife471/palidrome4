#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000
typedef char element;
typedef struct {
    element data[MAX_SIZE];
    int top;
}stacktype;

void init_stack(stacktype* s)
{
    // s가 가르키는 stacktype구조체의 탑의 값을 -1로 지정한다.
    s->top = -1;
}

int is_empty(stacktype* s)
{
    return (s->top == -1);
}
int is_full(stacktype* s)
{
    return (s->top == (MAX_SIZE - 1));
}
void push(stacktype* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "Stack Full!\n");
        return;
    }
    else
    {
        s->data[++s->top] = item;
    }
}
element pop(stacktype* s)
{
    if (is_empty(s))
    {

        exit(1);
    }
    else return s->data[(s->top)--];
}
element peek(stacktype* s)
{
    if (is_empty(s))
    {
        exit(1);
    }
    else return s->data[s->top];
}
void remove_spaces(char exp[])
{
    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] != ' ')
            exp[j++] = exp[i];
    }
    exp[j] = '\0';
}
void remove_special_chars(char exp[])
{
    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (!ispunct(exp[i]))
            exp[j++] = exp[i];
    }
    exp[j] = '\0';
}
int main()
{
    stacktype stack;
    char ch[MAX_SIZE];
    char str[MAX_SIZE];
    int i, len;
    int is_palindrome = 1;
    int k = 1;
    while (1)
    {
        printf("문자열을 입력하시오:");
        fgets(str, sizeof(str), stdin);
        remove_spaces(str);
        remove_special_chars(str);
        len = strlen(str) - 1;

        init_stack(&stack);

        for (i = 0; i < len / 2; i++)
        {
            if (isalpha(str[i]))
            {
                push(&stack, tolower(str[i]));
            }
        }

        for (i = (len + 1) / 2; i < len; i++)
        {
            if (isalpha(str[i]))
            {
                if (tolower(str[i]) != pop(&stack))
                {
                    is_palindrome = 0;
                    break;
                }
            }
        }

        if (is_palindrome)
        {
            printf("회문입니다.\n");
        }
        else
        {
            printf("회문이아닙니다.\n");
        }
        is_palindrome = 1;
        printf("계속 입력 하시겠습니까?(Yes/No)\n");
        fgets(ch, sizeof(ch), stdin);
        if (strcmp(ch, "Yes\n") == 0)
            continue;
        else if (strcmp(ch, "No\n") == 0)
            break;
        else
            break;

    }
    return 0;

}
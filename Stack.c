#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int stack[100];
size_t count = 0;

bool is_empty() {
    return count == 0;
}

bool is_full()  {
    return count == 100;
}

void push(int value)    {
    if(is_full())   {
        printf("Stack ist voll!\n");
        return;
    }

    stack[count] = value;
    count++;
}

int pop()   {
    if(is_empty())  {
        return 0;
    }

    count--;
    return stack[count];
}

int peek()  {
    if(is_empty)    {
        return 0;
    }

    return stack[count - 1];
}

size_t size()   {
    return count;
}

int main()  {
    push(2);
    push(3);

    int firstout = pop();
    int secondout = pop();

    printf("%d", firstout);
    printf("%d", secondout);
    return 0;
}
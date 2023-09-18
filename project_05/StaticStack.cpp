//Nome: Thiago De Oliveira Aguirre
//Tia : 32089589
#include "StaticStack.h"
#include "StaticQueue.h"


StaticQueue::StaticStack Create_Queue()
{
    StaticQueue::StaticStack stack = { 0, { 0 } };
    return stack;
}

bool Push(StaticQueue::StaticStack& stack, char elem)
{
    if (stack.count == Queue_Size)
    {
        return false;
    }

    stack.values[stack.count] = elem;
    ++stack.count;

    return true;
}

char Pop(StaticQueue::StaticStack& stack)
{
    if (IsEmpty(stack))
    {
        return '\0';
    }

    char temp = stack.values[stack.count - 1];
    stack.values[stack.count - 1] = '\0';
    --stack.count;

    return temp;
}

char Top(const StaticQueue::StaticStack& stack)
{
    if (IsEmpty(stack))
    {
        return '\0';
    }

    return stack.values[stack.count - 1];
}

int Size(const StaticQueue::StaticStack& stack)
{
    return sizeof(stack.values) / sizeof(stack.values[0]);
}

int Count(const StaticQueue::StaticStack& stack)
{
    return stack.count;
}

bool IsEmpty(const StaticQueue::StaticStack& stack)
{
    return stack.count == 0;
}

bool Clear(StaticQueue::StaticStack& stack)
{
    while (!IsEmpty(stack))
    {
        Pop(stack);
    }

    return IsEmpty(stack);
}
//www.geeksforgeeks.org/queue-using-stacks/ 
//www.youtube.com/watch?v=kPy95qTGVrY
//www.cplusplus.com/doc/tutorial/variables/
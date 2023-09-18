//Nome: Thiago De Oliveira Aguirre
//Tia : 32089589
#include "StaticQueue.h"
#include "StaticStack.h"

StaticQueue Create()
{
    StaticQueue queue = { Create_Queue() };

    return queue;
}

bool Enqueue(StaticQueue& queue, char elem)
{
    if (queue.Stack1.count == Size(queue))
    {
        return false;
    }
    Push(queue.Stack1, elem);
    return true;
}

char Dequeue(StaticQueue& queue)
{
    if (IsEmpty(queue))
    {
        return '\0';
    }
    int x = Top(queue.Stack1);
    Pop(queue.Stack1);
    if (IsEmpty(queue.Stack1))
        return x;
    int i = Dequeue(queue);
    Push(queue.Stack1, x);
    return i;
}

int Front(const StaticQueue& queue)
{
    return IsEmpty(queue) ? '\0' : queue.Stack1.values[0];
}

int Size(const StaticQueue& queue)
{
    return sizeof(queue.Stack1.values) / sizeof(queue.Stack1.values[0]);
}

int Count(const StaticQueue& queue)
{
    return queue.Stack1.count;
}

bool IsEmpty(const StaticQueue& queue)
{
    return queue.Stack1.count == 0;
}

bool Clear(StaticQueue& queue)
{
    while (!IsEmpty(queue))
    {
        Dequeue(queue);
    }

    return IsEmpty(queue);
}
//www.geeksforgeeks.org/queue-using-stacks/ 
//www.youtube.com/watch?v=kPy95qTGVrY
//www.cplusplus.com/doc/tutorial/variables/
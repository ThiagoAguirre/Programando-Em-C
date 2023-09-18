//Nome: Thiago De Oliveira Aguirre
//Tia : 32089589
#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__

const int Queue_Size = 8;

struct StaticQueue
{
    struct StaticStack
    {
        int count;
        char values[Queue_Size];
    };
    StaticStack Stack1;
};

StaticQueue Create();

bool Enqueue(StaticQueue& queue, char elem);

char Dequeue(StaticQueue& queue);

int Front(const StaticQueue& queue);

int Size(const StaticQueue& queue);

int Count(const StaticQueue& queue);

bool IsEmpty(const StaticQueue& queue);

bool Clear(StaticQueue& queue);

#endif
//www.geeksforgeeks.org/queue-using-stacks/ 
//www.youtube.com/watch?v=kPy95qTGVrY
//www.cplusplus.com/doc/tutorial/variables/
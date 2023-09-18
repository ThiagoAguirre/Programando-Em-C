#include "StaticQueue.h"
#include "StaticStack.h"
#include <iostream>
using namespace std;
int main()
{
    StaticQueue queue = Create();
    cout << "Insira um numero: ";
    int num;
    cin >> num;
    Enqueue(queue, num);
    cout << "Insira um numero: ";
    cin >> num;
    Enqueue(queue, num);
    cout << "Insira um numero: ";
    cin >> num;
    Enqueue(queue, num);
    cout << "Insira um numero: ";
    cin >> num;
    Enqueue(queue, num);
    cout << "Front: " << Front(queue) << "\n";
    cout << "Count: " << Count(queue) << "\n";
    cout << "Size: " << Size(queue) << "\n";
    Dequeue(queue);
    cout << "Count after dequeue: " << Count(queue) << "\n";
    cout << "Front after dequeue: " << Front(queue) << "\n";
}
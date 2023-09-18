// Nome:  Thiago De Oliveira Aguirre
//  tia:  32089589
#include <iostream>
#include <string>

struct Node
{
    int id;
    std::string name;
    Node* previous;
    Node* next;
};

struct LinkedList
{
    int count;
    Node* front;
    Node* back;
};

LinkedList* Create();

bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name); 

bool InsertAfter(LinkedList* list, int afterId, int id, std::string name); 

void Destroy(LinkedList* list); 

void AddFront(LinkedList* list, int id, std::string name); 

void AddBack(LinkedList* list, int id, std::string name);

Node* RemoveFront(LinkedList* list);

Node* RemoveBack(LinkedList* list);

Node* RemoveNode(LinkedList* list, int elem);

Node* GetFront(LinkedList* list);

Node* GetBack(LinkedList* list);

Node* GetNode(const LinkedList* list, int elem);

int Count(LinkedList* list);

bool IsEmpty(const LinkedList* list);

bool Clear(LinkedList* list); 

void DestroyNode(Node* node);

Node* CreateNode(int id, std::string name, Node* next, Node* previous);

// Nome: Thiago De Oliveira Aguirre
//  Tia: 32089589
#include <iostream>
#include <clocale>
#include "DoublyLinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	int i;
	Node* Aux = list->front;

	for (i = 0; i < list->count; ++i)
	{
		cout << "[" << Aux->id << "] " << Aux->name << "\n";
		Aux = Aux->next;
	}

	cout << "\n";
}
void PrintListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia! (" << list->count << ")\n\n";
	}
	else
	{
		cout << "Lista (" << list->count << "): \n";
		Print(list);
	}
}
int main()
{
	LinkedList* list = Create();
	AddFront(list, 51, "Suns");
	AddBack(list, 47, "Nuggets");
	AddBack(list, 47, "Clippers");
	InsertAfter(list, 47, 42, "Mavericks");
	PrintListInfo(list);
	Destroy(list);
}
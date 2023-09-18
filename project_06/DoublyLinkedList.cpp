//Nome:Thiago de Oliveira Aguirre       
//Tia 32089589

#include "DoublyLinkedList.h"
#include <iostream>
#include <string>

LinkedList* Create()
{
	LinkedList* novaLista = new LinkedList
	{
		0, nullptr, nullptr
	};
	return novaLista;
}

//   Como há um aumento linear das interações do loop, a medida que o codigo aumenta. O tempo de execução será aumentado.
//   Isto se dá  Pela  medida que o comprimento da matriz é implementado  tanto no Before quanto no After. 

// Então o Before será O(n) por que o For feito está contendo a variavel, que ira ler a quantidade que declararemos no Count . 
// Assim, A demora que se da pela implementação das variaveis que implementaremos se da por causa da quantidade de coisas que declaremos no Count. 
// Por causa de quanto mais atribuições fizeremos na main, maior será a demora de leitura do codigo nas implementação do Count


// O(n)
bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name)
{
	if (IsEmpty(list))
	{
		return false;
	}
	Node* InsertBefore = CreateNode(id, name, nullptr, nullptr);
	Node* node = list->front;
	for (int i = 0; i < Count(list) - 1; i++)
	{
		if (beforeId == node->id)
			break;
		node = node->next;
	}
	if (node == list->back && beforeId != node->id)
	{
		delete InsertBefore;
		return false;
	}
	if (beforeId == list->front->id)
	{
		AddFront(list, id, name);
		return true;
	}
	InsertBefore->previous = node->previous;
	InsertBefore->next = node;
	node->previous->next = InsertBefore;
	list->count++;
	return true;
}

// Então o After será O(n) por que o For feito está contendo a variavel, que ira ler a quantidade que declararemos no Count . 
// Assim, A demora que se da pela implementação das variaveis que implementaremos se da por causa da quantidade de coisas que declaremos no Count. 
// Por causa de quanto mais atribuições fizeremos na main, maior será a demora de leitura do codigo nas implementação do Count

// O(n)
bool InsertAfter(LinkedList* list, int afterId, int id, std::string name)
{
	if (IsEmpty(list))
	{
		return false;
	}
	Node* InsertAfter = CreateNode(id, name, nullptr, nullptr);
	Node* node = list->back;
	for (int i = 0; i < Count(list) - 1; i++)
	{
		if (afterId == node->id)
			break;
		node = node->previous;
	}
	if (node == list->front && afterId != node->id)
	{
		delete InsertAfter;
		return false;
	}
	if (afterId == list->back->id)
	{
		AddBack(list, id, name);
		return true;
	}
	InsertAfter->next = node->next;
	InsertAfter->previous = node;
	node->next->previous = InsertAfter;
	node->next = InsertAfter;
	list->count++;
	return true;
}

void Destroy(LinkedList* list)
{
	Clear(list);
	delete list;
}

// O(n)
void AddFront(LinkedList* list, int id, std::string name)
{
	Node* node = CreateNode(id, name, list->front, list->back);
	if (IsEmpty(list))
	{
		list->front = node;
		list->back = node;
	}
	else
	{
		list->front->previous = node;
		list->front = node;
	}
	list->count++;
}

// O(n)
void AddBack(LinkedList* list, int id, std::string name)
{
	Node* node = CreateNode(id, name, list->front, list->back);
	if (IsEmpty(list))
	{
		list->front = node;
		list->back = node;
	}
	else
	{
		list->back->next = node;
		node->previous = list->back;
		list->back = node;
		list->front->previous = list->back;
	}
	list->count++;
}

// O(n)
Node* RemoveFront(LinkedList* list)
{
	Node* toRemove = list->front;
	if (list->front == list->back)
	{
		list->front = nullptr;
		list->back = nullptr;
	}
	else
	{
		list->front = list->front->next;
		list->front->previous = list->back;
		toRemove->next = nullptr;
		toRemove->previous = nullptr;
	}
	list->count--;
	return toRemove;
}

// O(n)
Node* RemoveBack(LinkedList* list)
{
	if (list->front == list->back)
	{
		return RemoveFront(list);
	}
	Node* toRemove = list->back;
	list->back->previous->next = list->front;
	list->back = list->back->previous;
	list->front->previous = list->back;
	list->count--;
	toRemove->next = nullptr;
	toRemove->previous = nullptr;
	return toRemove;
}

//O(n)
Node* RemoveNode(LinkedList* list, int elem)
{
	Node* toRemove = list->front;
	Node* previous = nullptr;
	while (toRemove != list->back && toRemove->id != elem)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	if (toRemove->id != elem)
		return nullptr;
	else if (toRemove == list->front)
		return RemoveFront(list);
	else if (toRemove == list->back)
		return RemoveBack(list);
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;
		toRemove->next->previous = previous;
		--list->count;
		toRemove->next = toRemove->previous = nullptr;
		return toRemove;
	}
	return nullptr;
}


Node* GetFront(LinkedList* list)
{
	return list->front;
}

Node* GetBack(LinkedList* list)
{
	return list->back;
}

Node* GetNode(const LinkedList* list, int elem)
{
	Node* node = list->front;
	while (node != nullptr)
	{
		if (node->id == elem)
		{
			return node;
		}
		node = node->next;
	}
	return nullptr;
}

int Count(LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return (list->front == nullptr) && (list->back == nullptr) || (list->count == 0);
}

bool Clear(LinkedList* list)
{
	while (!IsEmpty(list))
	{
		RemoveBack(list);
	}
	list->count = 0;
	return IsEmpty(list);
}
Node* CreateNode(int id, std::string name, Node* next, Node* previous)
{
	Node* node = new Node;
	node->id = id;
	node->name = name;
	node->next = next;
	node->previous = previous;
	return node;
}

// Big O
void DestroyNode(Node* node)
{
	delete node;   
}

//Lista Circular duplamente Ligada! 
// Professor como eu fiz uma lista circular duplamente ligada, a primeira coisa que eu mudei foi a indentação do LinkedList já que era Circular para atender A exigencia do main
// Depois implementei os Insert Before e After  no cpp e H. Tive que arrumar os id, que eram data. Arrumando a identação conforme a exigencia do main que era de não mudar. 
// E logo depois fiz os codigos de Insert Before e After, eu não sei como mudar o -->> for (int i = 0; i < Count(list) - 1; i++) Este - 1 que tira da lista. Assim, gostaria depois de saber outras 
// maneiras que poderiam ser utilizadas para mudar esse count -1 que funciona, mesmo eu achando que não é a melhor maneira  para funcionar em meu codigo. Pois se colocar em outra 
// Implementação de outro codigo, eu acho que ira dar um aviso. Mas nesta prova consegui, com que funcionasse tudo que voce pediu! 

//Referencia que utilizei!
//www.geeksforgeeks.org/linked-list-set-2-inserting-a-node
//www.cplusplus.com/reference/list/list/insert/
//www.cplusplus.com/forum/general/34129/

// Referencia que eu usei para Fazer saber sobre o BigO
//estevestoni.medium.com/iniciando-com-a-nota%C3%A7%C3%A3o-big-o-be996fa3b47b
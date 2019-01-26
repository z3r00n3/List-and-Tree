#pragma once

#include <ostream>

template <class KeyT, class DataT>
struct Node {
	KeyT key;
	DataT data;
	Node<KeyT, DataT> *next;
};

template <class KeyT, class DataT>
class List {
private:
	Node<KeyT, DataT> *head;

public:
	List();
	~List();

	void AddNode(KeyT key, DataT data);
	DataT DeleteNode(KeyT key);
	bool IsNodeExist(KeyT key);
	DataT GetData(KeyT key);

	friend std::ostream& operator<<(std::ostream& os, const List<KeyT, DataT>& obj)
	{
		Node<KeyT, DataT> *tmp = obj.head;

		if (!tmp) os << "EMPTY";
		while (tmp)
		{
			os << tmp->key << '-' << tmp->data;
			if (tmp->next) os << " -> ";
			tmp = tmp->next;
		}
		os << " -> NULL";

		return os;
	};
};

template <class KeyT, class DataT>
List<KeyT, DataT>::List()
{
	head = NULL;
}

template <class KeyT, class DataT>
List<KeyT, DataT>::~List()
{
	Node<KeyT, DataT> *current = NULL, *tmp = NULL;

	if (head)
	{
		current = head;

		while (current)
		{
			tmp = current->next;
			delete current;
			current = tmp;
		}
	}
}

template <class KeyT, class DataT>
void List<KeyT, DataT>::AddNode(KeyT key, DataT data)
{
	Node<KeyT, DataT> *prev = NULL, *current = NULL;
	Node<KeyT, DataT> *node = new Node<KeyT, DataT>;
	node->key  = key;
	node->data = data;
	node->next = NULL;

	if (head == NULL)
		head = node;
	else {
		current = head;
		while (current)
		{
			prev = current;
			current = current->next;
		}

		prev->next = node;
	}
}

template <class KeyT, class DataT>
DataT List<KeyT, DataT>::DeleteNode(KeyT key)
{
	Node<KeyT, DataT> *prev = NULL, *current = NULL;
	DataT ret = (DataT)NULL;

	if (!head)
		return ret;
	else {
		current = head;
		while (current && current->key != key)
		{
			prev = current;
			current = current->next;
		}

		if (current == NULL)
			return ret;

		if (current == head)
			head = head->next;
		else
			prev->next = current->next;

		ret = current->data;
		delete current;

		return ret;
	}
}

template <class KeyT, class DataT>
bool List<KeyT, DataT>::IsNodeExist(KeyT key)
{
	Node<KeyT, DataT> *current = head;

	while (current)
	{
		if (current->key == key)
			return true;
		current = current->next;
	}

	return false;
}

template <class KeyT, class DataT>
DataT List<KeyT, DataT>::GetData(KeyT key)
{
	Node<KeyT, DataT> *current = head;

	while (current)
	{
		if (current->key == key)
			return current->data;
		else
			current = current->next;
	}

	return (DataT)NULL;
}

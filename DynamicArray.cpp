#include "DynamicArray.h"

President::President(char i_name, float i_term, int i_palaceArea)
{
    name = i_name;
    term = i_term;
    palace_area = i_palaceArea;
}

void President::print() const
{
    cout << "Name: " << name << "; In service for: " << term << " years; Palace area: " << palace_area <<"\n";
}


DynamicArray::DynamicArray()
{
    array = new President[ARRAY_SIZE];
}
DynamicArray::~DynamicArray()
{
    delete[] array;
}

void DynamicArray::Realloc(int new_size){
    auto* new_array = new President[new_size];

    if(new_size < initial_size)
        initial_index = new_size;

    for(int i = 0; i < initial_index; i++)
        new_array[i] = array[i];

    delete[] array;
    array = new_array;
    initial_size = new_size;
}

void DynamicArray::push_back(const President& object)
{
    if(initial_index >= initial_size)
        Realloc(initial_size * 2);

    array [initial_index] = object;
    initial_index++;
}

 President DynamicArray::pop_back()
{
    if(initial_index == 0)
        return President();

    initial_index--;
    President copy(array[initial_index]);
    array [initial_index].~President();
    return copy;
}

const President& DynamicArray::get(int index) const
{
    if(index < 0 || index > initial_size)
        throw out_of_range("Index is out of range");

    return array[index];
}

void DynamicArray::print() const
{
    if(initial_index == 0)
        cout << "\nArray is empty!";

    else
        for(int i = 0; i < initial_index; i++)
            array[i].print();
}

bool DynamicArray::clear()
{
    if(initial_index == 0)
        return false;

    initial_index = 0;
    initial_size = ARRAY_SIZE;
    delete[] array;
    return true;
}

void DynamicArray::push_front(const President& object)
{
    if(initial_index >= initial_size)
        Realloc(initial_size * 2);

    for(int i = initial_index; i > 0; i--)
        array[i] = array[i-1];

    array[0] = object;
    initial_index++;
}

President DynamicArray::pop_front() {
    if(initial_index == 0)
        throw out_of_range("Array is empty!");

    President copy(array[0]);
    for(int i = 0; i < initial_index; i++)
        array[i] = array[i + 1];

    array[initial_index - 1].~President();
    initial_index--;
    return copy;
}

Node::Node(const President& object)
{
    data = object;
    next_item = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList()
{
    LinkedList::clear();
}


void LinkedList::push_front(const President& object)
{
    if(head == nullptr)
    {
        head = new Node(object);
        head->next_item = tail;
        n_size++;

        if(n_size == 1) tail = head;
        return;
    }

    Node* n_head = new Node(object);
    n_head->next_item = head;
    head = n_head;
    n_size++;
}

void LinkedList::push_back(const President& object)
{
    if(tail == nullptr)
    {
        tail = new Node(object);
        n_size++;

        if(n_size == 1) head = tail;
        return;
    }

    Node* n_tail = new Node(object);
    tail->next_item = n_tail;
    tail = n_tail;
    n_size++;
}

const President& LinkedList::get(int index) const
{
    if(index < 0)
        throw out_of_range("Index is out of range");

    Node* cur = head;
    for(int i = 0; i < index; i++)
    {
        cur = cur->next_item;
    }

    return cur->data;
}

President LinkedList::pop_front()
{
    if(LinkedList::empty())
        return President();

    Node* copy = head;
    head->~Node();
    head = copy->next_item;
    n_size--;
    return copy->data;
}

President LinkedList::pop_back()
{
    if(LinkedList::empty())
        return President();

    Node* cur = head;
    President copy(President(tail->data));

    while(cur->next_item->next_item != nullptr)
    {
        cur = cur->next_item;
    }

    tail->~Node();
    cur->next_item = nullptr;
    tail = cur;
    tail->next_item->~Node();
    n_size--;
    return copy;
}

void LinkedList::print() const
{
    if(LinkedList::empty())
    {
        cout << "List is empty!\n";
        return;
    }

    Node* cur = head;
    for(int i = 0; i < n_size; i++)
    {
        cur->data.print();
        cur = cur->next_item;
    }
}

bool LinkedList::clear()
{
    if(LinkedList::empty())
        return false;

    Node *next = head->next_item;
    while(next != nullptr)
    {
        head->~Node();
        head = next;
        next = head->next_item;
    }
    return true;
}

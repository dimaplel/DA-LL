#ifndef ASD2_1_DYNAMICARRAY_H
#define ASD2_1_DYNAMICARRAY_H
#endif //ASD2_1_DYNAMICARRAY_H

#include "include.h"
#include "structure.h"

struct DynamicArray{
    President *array;
    int cursor = 0;
    int cur_size = ARRAY_SIZE;

    DynamicArray()
    {
        array = new President[ARRAY_SIZE];
    }
    ~DynamicArray()
    {
        delete[] array;
    }

    void Realloc(int new_size){
        auto* new_array = new President[new_size];

        if(new_size < cur_size)
            cur_size = new_size;

        for(int i = 0; i < cursor; i++)
            new_array[i] = array[i];

        delete[] array;
        array = new_array;
        cur_size = new_size;
    }

    bool empty() const
    {
        return cursor == 0;
    }

    void push_back(const President& object)
    {
        if(cursor == cur_size)
            Realloc(cur_size * 2);

        array[cursor] = object;
        cursor++;
    }

    President pop_back()
    {
        if(empty())
            return President();

        cursor--;
        President copy = array[cursor];
        array[cursor].~President();
        return copy;
    }

    President get(int index) const
    {
        if(index < 0 || index > cur_size)
            throw out_of_range("Index is out of range");

        return array[index];
    }

    int size() const
    {
    if(empty())
        return 0;
    return cursor;
    }

    void print() const
    {
        if(empty()) cout << "\nArray is empty!";
        else
        {
            for(int i = 0; i < cursor; i++)
            {
                array[i].print();
            }
        }
    }

    bool clear()
    {
        if(empty())
            return false;

        cursor = 0;
        cur_size = 1;
        delete[] array;
        return true;
    }

    void push_front(const President& object)
    {
        if(cursor >= cur_size - 1)
            Realloc(cur_size * 2);

        for(int i = cur_size; i > 0; i--)
            array[i] = array[i-1];

        array[0] = object;
        cursor++;
    }

    bool pop_front() {
        if(empty())
            return false;

        for(int i = 0; i < cursor; i++) {
            array[i] = array[i + 1];
        }
        cursor--;
        return true;
    }

};

struct Node
{
    President data;
    Node* next_item = nullptr;

    Node(const President& object) : data(object), next_item(nullptr) {}
    ~Node()
    = default;
};

struct LinkedList
{
    Node *head;
    Node *tail;
    int n_size = 0;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList()
    = default;

    bool empty()
    {
        return head == nullptr;
    }

    void push_front(President &object)
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

    void push_back(President &object)
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

    President get(int index) const
    {
        if(index <= 0)
            throw out_of_range("Index is out of range");

        Node* cur = head;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next_item;
        }

        return cur->data;
    }

    President pop_front()
    {
        Node* copy = head;
        delete head;
        head = copy->next_item;
        n_size--;
        return copy->data;
    }

    President pop_back()
    {
        Node* cur = head;
        for(int i = 0; i < n_size - 1; i++)
        {
            cur = cur->next_item;
        }
        delete tail;
        tail = cur;

        Node* _cur = cur->next_item;
        delete cur->next_item;
        n_size--;
        return _cur->data;
    }

    int size() const
    {
        return n_size;
    }

    void print() const
    {
        if(n_size == 0)
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

    bool clear()
    {
        if(empty())
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


};
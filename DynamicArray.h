#ifndef ASD2_1_DYNAMICARRAY_H
#define ASD2_1_DYNAMICARRAY_H

#include <ctime>
#include <cstdlib>
#include <iostream>

#define ARRAY_SIZE 2

using namespace std;

struct President
{
    char name;
    float term;
    int palace_area;

    President(char i_name = '.', float i_term = 0, int i_palaceArea = 0);
    ~President() = default;

    void print() const;
};

struct DynamicArray{
    President *array;
    int _size = 0;
    int capacity = ARRAY_SIZE;

    DynamicArray();
    ~DynamicArray();

    void Realloc(int new_size);

    void push_back(const President& object);

    President pop_back();

    // President вернёт копию объекта (лишнее копирование, как по мне)
    // можешь вернуть const President& чтобы нельзя было менять данные в массиве или же
    // можешь вернуть President&, если не против, чтобы с помощью get() можно было менять данные в массиве
    const President& get(int index) const;

    // Все инициализированные функции (те что имеют тело) в хедере неявно обозначаются как inline.
    // Это значит, что компилятор будет быстрее вызывать эти функции, но при этом
    // время компиляции и размер исходника будет больше

    // inline лучше обозначать маленькие функции, например эту
    // noexcept тоже по дефолту ставится и говорит о том, что в функции нет throw и она не может
    // прервать программу в runtime
    inline int size() const noexcept {return _size;}

    void print() const;

    bool clear();

    void push_front(const President& object);

    // ты не возвращаешь копию
    President pop_front();

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

    inline int size() const noexcept { return n_size; }

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

#endif //ASD2_1_DYNAMICARRAY_H
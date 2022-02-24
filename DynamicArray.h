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

    President(char i_name = 'A', float i_term = 0, int i_palaceArea = 0);
    ~President() = default;

    void print() const;
};

struct DynamicArray{
    President *array;
    int initial_index = 0;
    int initial_size = ARRAY_SIZE;

    DynamicArray();
    ~DynamicArray();

    void Realloc(int new_size);

    void push_back(const President& object);

    President pop_back();

    const President& get(int index) const;

    inline int size() const noexcept {return initial_index;}

    void print() const;

    bool clear();

    void push_front(const President& object);

    President pop_front();

};

struct Node
{
    President data;
    Node* next_item = nullptr;

    Node(const President& object);
    ~Node()
    = default;
};

struct LinkedList
{
    Node *head;
    Node *tail;
    int n_size = 0;

    LinkedList();
    ~LinkedList();

    inline bool empty() const noexcept {return head == nullptr;}

    void push_front(const President& object);

    void push_back(const President& object);

    const President& get(int index) const;

    President pop_front();

    President pop_back();

    inline int size() noexcept {return n_size;}

    void print() const;

    bool clear();
};
#endif //ASD2_1_DYNAMICARRAY_H
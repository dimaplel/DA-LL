#include <DynamicArray.h>

President::President(char i_name, float i_term, int i_palaceArea)
    : name(i_name), term(i_term), palace_area(i_palaceArea) {}

void President::print() const 
{cout << "Name: " << name << "; In service for: " << term << " years; Palace area: " << palace_area <<"\n";}

// dynamic array

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

    // а если new_size < _size? будет беда тогда в цикле ниже
    // не нужно дважды присваивать capacity = new_size
    if(new_size < capacity)
        _size = new_size;

    for(int i = 0; i < _size; i++)
        new_array[i] = array[i];

    delete[] array;
    array = new_array;
    capacity = new_size;
}

void DynamicArray::push_back(const President& object)
{
    if(_size >= capacity)
        Realloc(capacity * 2);

    array [_size] = object;
    _size++;
}

President DynamicArray::pop_back()
{
    if(_size == 0)
        return President();

    _size--;
    President copy = array [_size];
    array [_size].~President();
    return copy;
}

// President вернёт копию объекта (лишнее копирование, как по мне)
// можешь вернуть const President& чтобы нельзя было менять данные в массиве или же
// можешь вернуть President&, если не против, чтобы с помощью get() можно было менять данные в массиве
const President& DynamicArray::get(int index) const
{
    if(index < 0 || index > capacity)
        throw out_of_range("Index is out of range");

    return array[index];
}

void DynamicArray::print() const
{
    if(_size == 0) 
        cout << "\nArray is empty!";

    else 
    for(int i = 0; i < _size; i++)
        array[i].print();
}

bool DynamicArray::clear()
{
    if(_size == 0)
        return false;

    _size = 0;
    // зачем тебе ставить capacity 1, если у тебя есть define константа
    capacity = ARRAY_SIZE;
    delete[] array;
    return true;
}

void DynamicArray::push_front(const President& object)
{
    // не нужно capacity - 1 (вроде как лишнее действие будет)
    if(_size >= capacity)
        Realloc(capacity * 2);

    for(int i = _size; i > 0; i--)
        array[i] = array[i-1];

    array[0] = object;
    _size++;
}

// ты не возвращаешь копию
President DynamicArray::pop_front() {
    if(_size == 0)
        throw out_of_range("empty array");

    President copy(array[0]); // это равносильно President copy = array[0]
    for(int i = 0; i < _size; i++)
        array[i] = array[i + 1];

    // тут будет копия, так как array[i + 1] и array[i] на последнем шаге будут одинаковыми
    array[_size - 1].~President();
    _size--;
    return copy;
}
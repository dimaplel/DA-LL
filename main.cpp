#include "DynamicArray.h"

void vector_time(DynamicArray& vector)
{
    printf("Dynamic Array:\n");
    clock_t start_time = clock();
    for(int i = 0; i <= 50000; i++)
    {
        vector.push_back(President());
    }
    clock_t end_time = clock();
    double time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for pushing back: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 10000; i++)
    {
        vector.push_front(President());
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for pushing front: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 20000;i++)
    {
        vector.get(rand() % 32768);
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for getting elements: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_front();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for popping front: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_back();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for popping back: " << time << " seconds\n";
}

void list_time(LinkedList& vector)
{
    printf("Linked List:\n");
    clock_t start_time = clock();
    for(int i = 0; i <= 50000; i++)
    {
        vector.push_back(President());
    }
    clock_t end_time = clock();
    double time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for pushing back: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 10000; i++)
    {
        vector.push_front(President());
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for pushing front: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 20000;i++)
    {
        vector.get(rand() % 32768);
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for getting elements: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_front();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for popping front: " << time << " seconds\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_back();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for popping back: " << time << " seconds\n";
}

int main() {
    srand(time(NULL));
    DynamicArray data;
    LinkedList list;

    vector_time(data);
    printf("\n");
    list_time(list);

    for(int i = 0; i < 15; i++)
    {
        list.push_back(President());
    }
    return 0;
}
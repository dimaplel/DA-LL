#include "DynamicArray.h"

void vector_time(DynamicArray& vector)
{
    clock_t start_time = clock();
    for(int i = 0; i <= 50000; i++)
    {
        vector.push_back(President());
    }
    clock_t end_time = clock();
    double time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for first step: " << time << "\n";

    start_time = clock();
    for(int i = 0; i <= 10000; i++)
    {
        vector.push_front(President());
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for second step: " << time << "\n";

    start_time = clock();
    for(int i = 0; i <= 20000;i++)
    {
        vector.get(rand() % 32768);
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for third step: " << time << "\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_front();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for fourth step: " << time << "\n";

    start_time = clock();
    for(int i = 0; i <= 5000;i++)
    {
        vector.pop_back();
    }
    end_time = clock();
    time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time for fifth step: " << time << "\n";
}

int main() {
    srand(time(NULL));
    DynamicArray data;
    vector_time(data);
    return 0;
}

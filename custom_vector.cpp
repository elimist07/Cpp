#include <iostream>
using namespace std;
class DynamicArray
{
private:
    int array_size;
    int capacity;
    int *array = NULL;

public:
    DynamicArray()
    {
        array_size = 0;
        capacity = 1;
        array = new int[capacity];
    }

    DynamicArray(int capacity)
    {
        array_size = 0;
        this->capacity = capacity;
        int *array = new int[capacity];
    }

    void insert(int element)
    {

        if (array_size == capacity)
            size_increase();
        array[array_size] = element;
        array_size++;
    }

    
    void show()
    {
        for (int a = 0; a < array_size; ++a)
            std::cout << array[a] << std::endl;
    }


    void size_increase()
    {
        int *temp_array = new int[capacity * 2];
        capacity = capacity * 2;

        for (int i = 0; i < array_size; ++i)
        {
            temp_array[i] = array[i];
        }

        delete[] array;
        array = temp_array;
    }
};
int main()
{
    DynamicArray arr;
    arr.insert(5);
    arr.insert(6);
    arr.insert(8);
    arr.show();
    return 0;
}
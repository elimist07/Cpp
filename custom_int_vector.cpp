#include <iostream>
using namespace std;
class DynamicArray
{
private:
    int array_size;
    int capacity;
    int *array = NULL;

public:
    // calls constructor
    DynamicArray()
    {
        array_size = 0;
        capacity = 1;
        array = new int[capacity];
    }
    // calls constructor and gives size of user input
    DynamicArray(int capacity)
    {
        array_size = 0;
        this->capacity = capacity;
        int *array = new int[capacity];
    }
    // inserts element to last position
    void push_back(int element)
    {

        if (array_size == capacity)
            size_increase();

        array[array_size] = element;
        array_size++;
    }

    void insert(int position, int element)
    {
        if (position > array_size || position < 0)
        {
            std::cout << "Error: Position out of bound" << std::endl;
            return;
        }
        array_size += 1;
        if (array_size == capacity)
            size_increase();
        for (int i = array_size - 1; i >= position; --i)
        {
            array[i + 1] = array[i];
            if (i == position)
                break;
        }
        array[position] = element;
    }

    void del(int position)
    {
        if (position > array_size || position < 0)
        {
            std::cout << "Error: Position out of bound" << std::endl;
            return;
        }
        if (array_size == capacity)
            size_decrease();
        for (int i = position; i <= array_size - 1; ++i)
        {
            auto temp=array[i];
            array[i ] = array[i+1];
            array[i+1]=temp;
        }
        array_size -= 1;
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

    // deletes last element of array
    void pop()
    {
        array[array_size - 1] = 0;
        array_size--;
        if (array_size == capacity )
            size_decrease();
    }

    void size_decrease()
    {
        int *temp = new int[capacity / 2];
        capacity = capacity / 2;
        for (int i = 0; i < array_size; ++i)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }

    int getsize()
    {
        return array_size;
    }

    void show()
    {
        for (int a = 0; a < array_size; ++a)
            std::cout << array[a] << std::endl;
    }

    bool isempty()
    {
        if (array_size == 0)
            return 1;
        else
            return 0;
    }
    int getcapacity()
    {
        return capacity;
    }
    // calls deconstructor,its needed to free dyanmically allocated memory above
    ~DynamicArray()
    {
    }
};
int main()
{
    DynamicArray arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(10);
    arr.pop();
    arr.show();
    cout << "array size=" << arr.getsize() << endl;
    cout << "capacity=" << arr.getcapacity() << endl;
    // cout << arr.isempty() << endl;
    arr.insert(0, 101);
    arr.insert(1, 102);
    arr.insert(2, 103);
    arr.insert(3, 104);
    arr.insert(4, 105);
    arr.del(0);
    arr.show();
    cout << "Capacity is" << arr.getcapacity();
    return 0;
}
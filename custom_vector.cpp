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
    void insert(int element)
    {

        if (array_size == capacity)
            size_increase();

        array[array_size] = element;
        array_size++;
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
        if (array_size == capacity / 2)
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
    //calls deconstructor,its needed to free dyanmically allocated memory above
    ~DynamicArray(){

    }
};
int main()
{
    DynamicArray arr;
    arr.insert(5);
    arr.insert(6);
    arr.insert(8);
    arr.insert(10);
    arr.pop();
    arr.show();
    cout << "array size="<<arr.getsize()<<endl;
    cout << "capacity="<<arr.getcapacity()<<endl;
    cout << arr.isempty()<<endl;
    return 0;
}
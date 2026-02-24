#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline T sum(T a[], int size, T acc = 0)
{
    for (int i = 0; i < size; i++)
        acc += a[i];
    return acc;
}

int main()
{
    int size;
    cout << "Enter Size: ";
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cout << "a" << "[" << i << "]" << "=?";
        cin >> a[i];
    }
    int total = sum(a, size);
    cout << "Sum: " << total << endl;
        cout << "Sum: " << sum(a,size,4) << endl;

}
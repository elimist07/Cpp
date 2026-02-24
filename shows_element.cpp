#include <iostream>
using namespace std;
template <class T>
inline void sub(const T a[], int size, T s = 0)
{
    for (int i = 0; i < size; ++i)
        cout << "a" << "[" << i << "]=" << a[i] << endl;
}

int main()
{
    int size;
    cout << "Array size: ";
    cin >> size;
    double a[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "a" << "[" << i << "]:?";
        cin >> a[i];
    }
    sub(a, size);
    return 0;
}
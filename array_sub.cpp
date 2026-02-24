#include <iostream>
using namespace std;
template <class SUB>
inline SUB subtract(const SUB a[], int size)
{
    SUB diff = 0;
    if (size> 1)
    {
        for (int i = 1; i < size; ++i)
        {
            diff += a[i];
        }
        diff = a[0] - diff;
    }
    return diff;
}
int main()
{
    int size;
    cout << "Array size: ";
    cin >> size;
    int a[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter data for a[" << i << "]:";
        cin >> a[i];
    }
    cout << "Difference =" << (subtract(a, size)) << endl;
    return 0;
}
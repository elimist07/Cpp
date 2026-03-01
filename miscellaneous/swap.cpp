#include <iostream>
using namespace std;
inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
inline void swap(double &m, double &n)
{
    double temp = m;
    m = n;
    n = temp;
}//cpp has overhead which allows fucntions to have same function 
//separates which to using type signature...
int main()
{
    int a = 2, b = 3;
    cout << "Unswaped: " << a << "," << b << endl;
    swap(a, b);
    cout << "Swaped: " << a << "," << b << endl;
    double m = 1.2, n = 3.9;
    cout << "Unswaped: " << m << "," << n << endl;
    swap(m, n);
    cout << "Swaped: " << m << "," << n << endl;
    return 0;
}
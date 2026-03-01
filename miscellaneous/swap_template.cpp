#include <iostream>
#include <complex>
using namespace std;
template <class T>
inline void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 2, b = 3;
    cout << "Unswaped: " << a << "," << b << endl;
    myswap(a, b);
    cout << "Swaped: " << a << "," << b << endl;
    double m = 1.2, n = 3.9;
    cout << "Unswaped: " << m << "," << n << endl;
    myswap(m, n);
    cout << "Swaped: " << m << "," << n << endl;
    complex<double> r(1.2, 5.7), s(4.8, 8.2);
    cout << "Unswaped: " << r << "," << s << endl;
    myswap(r, s);
    cout << "Swaped: " << r << "," << s << endl;

    return 0;
}
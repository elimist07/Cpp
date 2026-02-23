#include <iostream>
#include <vector>
using namespace std;
const int N = 1000;
inline void sum(int *p, int n, vector<int> d[])
{
     *p = 0;
    for (int i = 0; i < n; ++i)
        *p = *p + d[i][0];//sums upto 0 to n-1
}
int main()
{
    std::vector<int> data[N]; //vector=resizeable array,::=scope resolution operator
    int accum = 0;
    for (int i = 0; i < N; i++)
    {

        data[i].push_back(i);//adds element to ith element
    }
    sum(&accum, N, data);
    cout << "sum is " << static_cast<long>(accum)<<endl;
    return 0;
}

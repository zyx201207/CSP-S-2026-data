#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int f = 1, x = 0;
    int ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int a, b;
int main()
{
    a = read(), b = read();
    cout << a + b << endl;
    return 0;
}

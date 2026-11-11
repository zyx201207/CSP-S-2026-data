#include <iostream>
#include <string>
using namespace std;
//
int n;
char a[1000000000];
int f = -1;
int aa = 0;
//
int main()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    //
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        char k;
        cin >> k;
        for (int j = 0; j < m; j++)
        {
            f++;
            a[f] = k;
            //cout << a[f];
            //cout << f;
        }
    }
    //
    //cout << endl;
    //
    for (int i = 0; i <= (f + 1) / 2; i++)
    {
        if (a[i] != a[f - i])
        {
            aa++;
            //cout << a[i];
            //cout << i << ',' << f - i;
        }
    }
    //
    //cout << a << endl;
    cout << aa;
    return 0;
}
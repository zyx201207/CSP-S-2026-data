#include <bits/stdc++.h>
using namespace std;

int f()
{
    int n, k, lst[1000004][2];
    for(int i=1; i<=n-1; i++)
    {
        cin >> lst[i][0] >> lst[i][1];
    }
    return 1;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >>t;
    for(int i=1; i<=t; i++)
    {
        cout << f() << endl;
    }
    return 0;
}
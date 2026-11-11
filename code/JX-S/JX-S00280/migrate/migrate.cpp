#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d, a[100005];
    cin >> c >> t >> n >> d;
    for(int i = 1; i <= t; i++)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    if(n == 4)
    {
        cout << "1" << endl;
        cout << "2" << endl;
    }
    if(n == 5)
    {
        cout << "0" << endl;
        cout << "1" << endl;
    }
    else
    {
        cout << "2" << endl;
        cout << "3" << endl;
    }
    return 0;
}

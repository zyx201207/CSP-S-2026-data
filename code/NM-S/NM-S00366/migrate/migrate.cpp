#include <bits/stdc++.h>
using namespace std;
freopen("migrate.in", "r", stdin);
freopen("migrate.out", "w", stdout);
int main()
{
    int n,d;
    cin >> n >> d;
    int s;
    s = n / d;
    int a[1],a[2];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(a[1] > a[2])
            {
                cout << s;
            }
            else
            {
                d++;
            }
            n = s * d;
        }
    }
    cout << n;
    return 0;
}

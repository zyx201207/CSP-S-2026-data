#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <n; i++)
    {
        cin >> a[i];
    }
    int mx = 0;
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, a[i]);
        }
        cout << mx << "\n";
    }
    if (m == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                mx = max(mx, (a[i] & a[j]));
            }
        }
        cout << mx << "\n";
    }
    return 0;
}

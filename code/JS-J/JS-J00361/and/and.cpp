#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        sort(a + 1, a + n + 1);
        cout << a[n];
    }
    else if (m == n)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] &= a[i + 1];
            s = a[i];
        }
        cout << s;
    }
    else if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if ((a[i] & a[j]) > s && i != j)
                {
                    s = (a[i] & a[j]);
                }
            }
        }
        cout << s;
    }
    else if (m == n - 1)
    {
        sort(a + 1, a + n + 1);
        for (int i = 2; i <= n; i++)
        {
            a[i] &= a[i + 1];
            s = a[i];
        }
        cout << s;
    }
    else
    {
        sort(a + 1, a + n + 1);
        s = a[n - m + 1];
        cout << s;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, cnt = 0;
    long long m;
    cin >> n >> m;
    long long a[n + 2], b[n + 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i + 1] - a[i];
    }
    while (m > 0)
    {
        a[1]++;
        m--;
        sort(a + 1, a + n + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i + 1])
        {
            cnt++;
        }
    }
    if (cnt > 0)
    {
        cnt++;
    }
    cout << cnt;
}

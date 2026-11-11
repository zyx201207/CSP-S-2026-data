#include <bits/stdc++.h>
using namespace std;

long long a[200005];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    long long maxnum = -2e9, maxn = -2e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxnum = max(maxnum, a[i]);
    }
    if (m == 1)
    {
        cout << maxnum;
        return 0;
    }
    if (m == n)
    {
        long long num = a[1];
        for (int i = 2; i <= n; i++)
        {
            num = (num & a[i]);
        }
        cout << num;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                maxn = max(maxn, (a[i] & a[j]));
            }
        }
        cout << maxn;
        return 0;
    }
    do
    {
        long long num = a[1];
        for (int i = 2; i <= m; i++)
        {
            num = (num & a[i]);
        }
        maxn = max(maxn, num);
    } while (next_permutation(a + 1, a + n + 1));
    cout << maxn;
    return 0;
}

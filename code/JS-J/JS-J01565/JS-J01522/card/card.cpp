#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], v[500005], la[500005], ans[500005];
int find(int i)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > i)
        {
            r = mid - 1;
        }
        if (a[mid] < i)
        {
            l = mid + 1;
        }
        if (a[mid] == i)
        {
            for (int j = mid; j <= n; j++)
            {
                if (a[j] != i) return j - 1;
            }
        }
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 500 && m <= 3000)
    {
        for (int i = 1; i <= n; i++)
        {
             for (int j = 1; j <= n; j++)
            {
                v[j] = 0;
                la[j] = 0;
            }
            for (int j = i; j <= n; j++)
            {
                v[a[j]] = 1;
                if (la[a[j]] != 0)
                {
                    for (int x = la[a[j]] + 1; x <= j - 1; x++)
                    {
                        v[a[x]] = 0;
                        la[a[x]] = 0;
                    }
                }
                la[a[j]] = j;
            }
            for (int j = 1; j <= m; j++)
            {
                if (v[j])
                ans[j]++;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        a[n + 1] = -1;
        for (int i = 1; i <= m; i++)
        {
            cout << find(i) << " ";
        }
    }
    return 0;
}

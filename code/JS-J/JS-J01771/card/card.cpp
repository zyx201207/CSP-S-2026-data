#include <bits/stdc++.h>
using namespace std;
//#define ll long long

int n, m;
int a[500005], num[300005], qum[300005];
int q[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) f = 0;
    }
    if (f)
    {
        for (int i = n; i >= 1; i--)
        {
            num[a[i]] = max(num[a[i]], i);
        }
        for (int i = 1; i <= m; i++) cout << a[i] << " ";
        return 0;
    }
    for (int t = 1; t <= n; t++)
    {
        memset(qum, 0, sizeof(qum));
        for (int i = t; i <= n; i++)
        {
            memset(q, 0, sizeof(q));

            for (int j = t; j <= i - 1; j++)
            {
                q[a[j]] += 1;
            }
            int f1 = 1;
            for (int j = i + 1; j <= n; j++)
            {
                if (q[a[j]] != 0)
                {
                    f1 = 0;
                    break;
                }
            }
            if (f1 && qum[a[i]] == 0)
                num[a[i]]++, qum[a[i]]++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << num[i] << " ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], c[N], b[M], cnt[M], r[M];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (b[a[i]])
        {
            c[b[a[i]]] = i;
        }
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (r[a[j]] < i)
            {
                cnt[a[j]]++;
                r[a[j]] = i;
                while(c[j])
                {
                    j = c[j];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}

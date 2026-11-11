#include <bits/stdc++.h>
using namespace std;

long long cnt[300005];
long long a[500005];
long long p[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        memset(p, 0, sizeof(p));
        int l = 0;
        int j = i;
        while(j <= n)
        {
            bool f = false;
            int j1;
            for (int k = 1; k <= l; k++)
            {
                if (p[k] == a[j])
                {
                    f = true;
                    j1 = k;
                    break;
                }
            }
            if (f)
            {
                for (int k = j1; k <= l; k++)
                {
                    p[k] = 0;
                }
                l = j1;
                p[j1] = a[j];
            }
            else
            {
                p[++l] = a[j];
            }
            j++;
        }
        for (int k = 1; k <= l; k++)
        {
            cnt[p[k]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}

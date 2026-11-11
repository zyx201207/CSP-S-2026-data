#include <bits/stdc++.h>
using namespace std;

int a[500005], ans[500005], sa[500005], cnt[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        memset(sa, 0, sizeof(sa));
        memset(cnt, 0, sizeof(cnt));
        int cur = 1;
        sa[1] = a[i];
        cnt[a[i]]++;
        for (int j = i + 1; j <= n; j++)
        {
            if (cnt[a[j]] != 0)
            {
                int num;
                for (int k = 1; k <= n; k++)
                {
                    if (sa[k] == a[j])
                    {
                        num = k;
                        break;
                    }
                }
                for (int k = num + 1; k <= n; k++)
                {
                    sa[k] = 0;
                }
            }
            else
            {
                sa[++cur] = a[j];
                cnt[a[j]]++;
            }
        }
        bool f = false;
        for (int j = 1; j <= n; j++)
        {
            ans[sa[j]]++;
            if (sa[j] == a[n]) f = true;
        }
        if (!f) ans[a[n]]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}

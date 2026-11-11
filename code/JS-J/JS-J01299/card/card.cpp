#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1], ans[m + 1];
    bool F[n + 1];
    memset(b, 0, sizeof b);
    memset(ans, 0, sizeof ans);
    memset(F, 0, sizeof F);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        if(F[i])
            continue;
        int f = i, cnt = 1;
        for(int j = i; j <= n; j++)
        {
            if(b[a[j]])
            {
                for(int k = b[a[j]]+1; k < j; k++)
                    b[a[k]] = 0;
                if(b[a[j]] == f)
                    cnt++, f = j, F[j] = 1;
            }
            b[a[j]] = j;
        }
        for(int j = i; j <= n; j++)
            if(b[a[j]])
            {
                b[a[j]] = 0, ans[a[j]] += cnt;
            }
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] <<" ";
    return 0;
}

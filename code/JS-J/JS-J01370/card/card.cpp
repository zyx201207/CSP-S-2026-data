#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int nxt[500005];
int pre[300005];
int ans[300005];
int dealt[500005];

int main()
{
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        if (pre[a[i]] == 0) pre[a[i]] = i;
        else
        {
            nxt[pre[a[i]]] = i;
            pre[a[i]] = i;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (dealt[i]) continue;
        int fac = 0;
        for (int j=i; j<=n; j++)
        {
            if (dealt[j]==0) fac++;
            dealt[j] = 1;
            if (nxt[j]==0) ans[a[j]]+=fac;
            else
            {
                j = nxt[j]-1;
            }
        }
    }

    for (int i=1; i<=m; i++)
    {
        cout << ans[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int* w;
ll** prim;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    w = new int[m + 1];
    prim = new ll*[n + m + 1];
    for(int i = 0;i <= n + m;i++)
    {
        prim[i] = new ll[n + m + 1];
        memset(prim[i],0x3f,sizeof(int) * (n + m + 1));
    }
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        int k,a,t;
        cin >> k;
        while(k--)
        {
            cin >> a >> t;
            prim[a][i + m] = t;
            prim[i + m][a] = t;
        }
    }
    for(int i = 1;i <= n + m;i++)
    {
        for(int j = 1;j <= n + m;j++)
        {
            if(i == j) continue;
            for(int k = 1;k <= n + m;k++) prim[i][j] = min(prim[i][j],prim[i][k] + prim[k][j]);
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << w[x] + w[y] + prim[x][y] << '\n';
    }
    return 0;
}

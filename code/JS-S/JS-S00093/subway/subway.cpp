#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[505],x,y,k[505],a[505][1005],t[505][1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> x >> y;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],x[505][500005];
bool b1[500005],b2[505];
int tot = 0,minn = 1e8;
void dfs(int cur,int ed)
{
    if (cur == ed)
    {
        minn = min(minn,tot);
        return;
    }
    b1[cur] = 1;
    for (int i = 1;i <= n;i++)
    {
        if(a[i][cur] == 0) continue;
        if(b2[i] == 1) continue;
        b2[i] = 1;
        tot += a[i][cur];
        for(int j = 1;j <= k[i];j++)
        {
            tot += a[i][x[i][j]];
            if(b1[x[i][j]] == 0) dfs(x[i][j],ed);
            tot -= a[i][x[i][j]];
        }
        tot -= a[i][cur];
        b2[i] = 0;
    }
    b1[cur] = 0;

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            int sta,time;
            cin >> sta >> time;
            a[i][sta] = time;
            x[i][j] = sta;
        }
    }
    while(q--)
    {
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        tot = 0,minn = 1e8;
        int s,e;
        cin >> s >> e;
        dfs(s,e);
        cout << minn + w[s] + w[e] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int zhan,xian;
};

int w[500005],t[505][5005];//500005
vector <int> a[505];
vector <Node> g[500005];
int k[505];
int x,y,minn=2e9;
bool vis[500005];

int AtoBtime(Node x,Node y)
{
    if (x.xian==y.xian) return 0;
    return t[x.xian][x.zhan]+t[y.xian][y.zhan];
}

int chuzhan(Node x)
{
    return w[x.zhan]+t[x.xian][x.zhan];
}

void dfs(int tm,Node now)
{
    if (now.zhan==y)
    {
        minn=min(minn,tm+chuzhan(now));
        return;
    }
    for (auto h:g[now.zhan])
    {
        if (vis[h.zhan]) continue;
        Node hc={now.zhan,h.xian};
        vis[h.zhan]=1;
        dfs(tm+AtoBtime(now,hc)+AtoBtime(hc,h),h);
        vis[h.zhan]=0;
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> k[i];
        for (int j=1;j<=k[i];j++)
        {
            int te;cin >> te;
            a[i].push_back(te);
            cin >> t[i][j];
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<k[i]-1;j++)
        {
            int u=a[i][j],v=a[i][j+1];
            g[u].push_back({v,i});
            g[v].push_back({u,i});
        }
    }
    for (int i=1;i<=q;i++)
    {
        minn=2e9;
        cin >> x >> y;
        for (int i=1;i<=n;i++)
        {
            for (auto o:a[i])
            {
                Node X={o,i};
                if (o==x) dfs(chuzhan(X),X);
            }
        }
        cout << minn << endl;
    }
    return 0;
}

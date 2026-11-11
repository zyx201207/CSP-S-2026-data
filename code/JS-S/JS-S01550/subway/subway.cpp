#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct node{
    long long x,y;
};
node f[500005];
long long dis[500005];
vector<long long> vin[500005];
vector<long long> vik[500005];
long long vis[500005];
long long vid[500005];
long long cnt = 0;
long long t[505][50005];
long long w[500005];
long long a[505][50005];
void qk()
{
    cnt = 0;
    for(int i = 1;i<=m;i++)
    {
        vis[i]=0;
        vid[i]=0;
        dis[i]=0;
    }
}
void sc(int x)
{
    int mi =x*2;
    if(mi>cnt)return;
    if(mi!=cnt&&f[mi+1].y<f[mi].y)mi++;
    if(f[x].y>f[mi].y)
    {
        swap(f[x],f[mi]);
        sc(mi);
    }
    return;
}
void dfs(int x)
{
    int mi = x/2;
    if(x==1)return;
    if(f[mi].y>f[x].y)
    {
        swap(f[mi],f[x]);
        dfs(mi);
    }
    return;
}
void bfs(int r)
{
    int num = 0;
    while(num<m)
    {
        node x = f[1];
        swap(f[1],f[cnt--]);
        sc(1);
        if(vis[x.x]==1)continue;
        vis[x.x]=1;
       // cout << x.x << " " << dis[x.x] << endl;
        num++;
        //cout << num << endl;
        dis[x.x]=min(x.y,dis[x.x]);
        for(int i = 0;i<vin[x.x].size();i++)
        {
            int u = vin[x.x][i];
            int di = t[u][x.x];
            if(vid[u]==1)continue;
            vid[u]=1;
            for(int j = 0;j<vik[u].size();j++)
            {
                int ju = vik[u][j];
                if(vis[ju]==1)continue;
                int dise = x.y+di+t[u][ju];
                if(dis[ju]>(dise)||dis[ju]==0)
                {
                    dis[ju]=dise;
                    f[++cnt].x=ju;
                    f[cnt].y=dise;
                    dfs(cnt);
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++)
    {
        cin >> w[i];
    }
    int sum = 1;
    for(int i = 1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j<=k;j++)
        {
            cin >> a[i][j];
            int u = a[i][j];
            cin >> t[i][u];
            vin[a[i][j]].push_back(sum);
            vik[sum].push_back(a[i][j]);
        }
        sum++;
    }
    while(q--)
    {
        qk();
        int x,y;
        cin >> x >> y;
        dis[x]=w[x];
        f[++cnt].x=x;
        f[cnt].y=w[x];
        dfs(cnt);
        bfs(x);
        cout << dis[y]+w[y] << endl;
    }
    return 0;
}

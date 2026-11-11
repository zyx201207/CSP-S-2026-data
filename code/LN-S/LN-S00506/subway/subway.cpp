#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int N = 550,M = 5e5+10;
int c,n,m,d,q;
ll g[N][N],w[M];
vector<pil>a[N],ra[M];
//每个铁路线经过哪些个点
//每个点经过哪些铁路线
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)cin>>w[i];
    for(int i = 1;i<=n;i++)
    {
        int ki;cin>>ki;
        for(int j = 1;j<=ki;j++)
        {
            int ai;ll ti;
            cin>>ai>>ti;
            a[i].push_back({ai,ti});
            ra[ai].push_back({i,ti});
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i = 1;i<=n;i++)g[i][i] = 0;
    for(int i = 1;i<=m;i++)
        for(int j = 0;j<(int)ra[i].size();j++)
            for(int k = j+1;k<(int)ra[i].size();k++)
            {
                int x = ra[i][j].fi,y = ra[i][k].fi;
                ll tx = ra[i][j].se,ty = ra[i][k].se;
                g[x][y] = g[y][x] = min(g[x][y],tx+ty);
                // cout<<x<<" "<<y<<" "<<tx+ty<<"\n";
            }
    for(int k = 1;k<=n;k++)
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    // for(int i = 1;i<=n;i++)
    // {
    //     for(int j = 1;j<=n;j++)
    //         cout<<g[i][j]<<" ";
    //     cout<<"\n";
    // }
    while(q--)
    {
        int sx,sy;ll ans = 0x3f3f3f3f3f3f3f3f;
        cin>>sx>>sy;
        for(pil fx:ra[sx])
            for(pil fy:ra[sy])
                ans = min(ans,fx.se+fy.se+g[fx.fi][fy.fi]);
        cout<<(ans+w[sx]+w[sy])<<"\n";
    }
    return 0;
}
/*
首先，发现铁路线与站台间有二分图结构
所以构造图可以直接求解小数据
发现站台数字是5e5，但是铁路线段只有500
每个站台只有d<=20个线
所以从站台枚举20个目标线路
构造线路间的转移矩阵
最后跑floyd
查询时枚举经过的线路
*/
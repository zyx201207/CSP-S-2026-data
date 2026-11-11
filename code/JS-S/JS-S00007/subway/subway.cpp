#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q;
const int maxn=5005;
const int maxv=5e4+5;
const int maxk=5e5+5;
const int maxm=505;
int w[maxk];
struct node
{
    int v,w;
};
vector<node> e[maxk];
int tot;
int dis[maxn][maxn];
int dis2[maxv];
inline void dij(int s)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    dis[s][s]=0;
    while (!q.empty())
    {
        int d=q.top().first;
        int u=q.top().second;
        q.pop();
        for (auto p:e[u])
        {
            int v=p.v,w=p.w;
            if (dis[s][u]+w<dis[s][v]) 
            {
                dis[s][v]=dis[s][u]+w;
                q.push({dis[s][v],v});
            }
        }
    }
}
inline void dij2(int s)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    for (int i=1;i<=m+tot;i++) dis2[i]=0x7f7f7f7f;
    dis2[s]=0;
    while (!q.empty())
    {
        int d=q.top().first;
        int u=q.top().second;
        q.pop();
        for (auto p:e[u])
        {
            int v=p.v,w=p.w;
            if (dis2[u]+w<dis2[v]) 
            {
                dis2[v]=dis2[u]+w;
                q.push({dis2[v],v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
   
    cin>> c>>n>>m>>d>>q;
   
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        int la=0;
        for (int j=1;j<=k;j++)
        {
            int a,t;
            cin >>a >> t;
            ++tot;
            if (la) 
            {
                e[la].push_back({m+tot,0});
                e[m+tot].push_back({la,0});
            }
            la=m+tot;
            e[a].push_back({m+tot,t});
            e[m+tot].push_back({a,t});
        }
    }
    if (c<=11)
    {
        memset(dis,0x7f,sizeof dis);
        for (int i=1;i<=m;i++) dij(i);
        for (int i=1;i<=q;i++)
        {
            int x,y;
            cin >>x>>y;
            cout << w[x]+w[y]+dis[x][y] << '\n';
        }
    }
    else
    {
        for (int i=1;i<=q;i++)
        {
            int x,y;
            cin >> x>>y;
            dij2(x);
            cout << dis2[y]+w[x]+w[y] << '\n';
        }
    }
    
    return 0;
}

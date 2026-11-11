#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,mm,k;
typedef pair<ll,int>pll;
const int N=5e5+5;
const int M=505;
vector<pll>g[N];
ll dis[N];
ll ww[N];
bool vis[N];
struct node{
    int poss;
    ll tt;
}a[N];
void add(int u,int v,int w)
{
    g[u].push_back({w,v});
}
void dij(int s)
{
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    priority_queue<pll,vector<pll>,greater<pll>>q;
    q.push({0,s});
    while(!q.empty())
    {
        auto noww=q.top();
        q.pop();
        ll d=noww.first;
        int u=noww.second;
        if(vis[u])continue;
        vis[u]=1;
        for(auto &edge:g[u])
        {
            ll w=edge.first;
            int v=edge.second;
            if(dis[v]==-1||dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>mm>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>ww[i];
    m=0;
    for(int i=1;i<=mm;i++)
    {
        cin>>k;
        m=m+(k-1)*k/2;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j].poss>>a[j].tt;
        }
        for(int i=1;i<k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
            //    cout<<a[i].poss<<' '<<a[j].poss<<'\n';
                add(a[i].poss,a[j].poss,a[i].tt+a[j].tt);
                add(a[j].poss,a[i].poss,a[i].tt+a[j].tt);
            }
        }
    }
    while(q--)
    {
        int xx,yy;
        cin>>xx>>yy;
        dij(xx);
        cout<<dis[yy]+ww[xx]+ww[yy]<<'\n';
    }
    return 0;
}
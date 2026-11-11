#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+550;
const int Q=1e5+5;
int c,n,m,d,qq;
ll w[N];
struct node
{
    int v;ll val;
    bool operator<(const node &t)const{return val>t.val;}
};
vector<node> e[N];
priority_queue<node> q;
bool vis[N];
ll dis[N];
void dijk(int x)
{
    for(int i=1;i<=m+n;i++) vis[i]=0,dis[i]=1e18;
    dis[x]=0;
    while(q.size()) q.pop();
    q.push({x,0});
    while(q.size())
    {
        int u=q.top().v;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(node p:e[u])
        {
            int v=p.v;
            if(dis[v]>dis[u]+p.val)
            {
                dis[v]=dis[u]+p.val;
                q.push({v,dis[v]});
            }
        }
    }
    return;
}
ll ans[Q];
struct Node
{
    int ord,x,y;
    bool operator<(const Node &t)const{return x<t.x;}
}qry[Q];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        while(k--)
        {
            int u;ll t;
            cin>>u>>t;
            e[u].push_back({m+i,t});
            e[m+i].push_back({u,t});
        }
    }
    for(int i=1;i<=qq;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        qry[i]={i,x,y};
    }
    sort(qry+1,qry+qq+1);
    for(int i=1;i<=qq;i++)
    {
        if(qry[i].x!=qry[i-1].x) dijk(qry[i].x);
        ans[qry[i].ord]=dis[qry[i].y]+w[qry[i].x]+w[qry[i].y];
    }
    for(int i=1;i<=qq;i++) cout<<ans[i]<<"\n";
    return 0;
}

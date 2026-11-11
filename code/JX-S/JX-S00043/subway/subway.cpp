#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int N=505;
int n,m,d,c,q,w[N],dis[M];
bool pd;
int v[M],w2[M];
vector<pair<int,int> > g[M];
struct node{
    int val,id;
    friend bool operator <(node x,node y)
    {
        return x.val>y.val;
    }
};
bool vis[M];
void dij(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<node> q;
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty())
    {
        int u=q.top().id;
        q.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u]=1;
        for(auto i:g[u])
        {
            int v=i.first,w=i.second;
            if(!vis[v] && dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push((node){dis[v],v});
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int T;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>v[j]>>w2[j];
        }
        T=w2[1];
        for(int j=1;j<=k;j++)
        {
            if(T!=w2[j])
            {
                pd=1;
            }
        }
        for(int j=1;j<=k;j++)
        {
            for(int z=j+1;z<=k;z++)
            {
                int u=v[j],v1=v[z],w1=w2[j]+w2[z];
                g[u].push_back(make_pair(v1,w1));
                g[v1].push_back(make_pair(u,w1));
            }
        }
    }
    if(!pd)
    {
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+(y-x)*T*2<<"\n";
        }
        return 0;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}

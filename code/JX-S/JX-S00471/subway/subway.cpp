#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=6e5+10;
typedef pair<int,int> pii;
int a[N],dist[N];
vector<pii> g[N];
void dijkstra(int s)
{
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dist[s]=0;
    q.push({dist[s],s});
    while(q.size())
    {
        auto tp=q.top();
        q.pop();
        int x=tp.first,y=tp.second;
        for(auto i:g[y])
        {
            int u=i.first,v=i.second;
            if(x+v<dist[u])
            {
                dist[u]=x+v;
                q.push({dist[u],u});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,m,n,q,d;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=m+1;i<=m+n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int u,v;
            cin>>u>>v;
            g[i].push_back({u,v});
            g[u].push_back({i,v});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dist[y]+a[x]+a[y]<<endl;
    }
    return 0;
}

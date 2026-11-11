#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> pii;
int a[N],dist[N],res[N];
int n,d;
vector<pii> g[N];
void dijkstra(int s)
{
    memset(dist,0x3f,sizeof(dist));
    memset(res,0,sizeof(res));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dist[s]=0;
    res[s]=1;
    q.push({dist[s],s});
    while(q.size())
    {
        auto tp=q.top();
        q.pop();
        int x=tp.first,y=tp.second;
        for(auto i:g[y])
        {
            int u=i.first,v=i.second;
            if(x+v<dist[u]&&x+v<=d)
            {
                dist[u]=x+v;
                q.push({dist[u],u});
                res[u]=1;
            }
            else if(dist[u]==x+v) res[u]+=1;
        }
    }
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i].push_back({j,abs(a[i]-a[j])});
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
        for(int j=1;j<=n;j++)
        {
            if(res[j]==2) ans++;
        }
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int C,T=1;
    cin>>C>>T;
    while(T--) solve();
    return 0;
}

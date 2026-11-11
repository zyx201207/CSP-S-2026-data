#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define popcount(x) __builtin_popcount(x)
#define endl '\n'
int o,n,m,d,q,tot;
const int N = 5e5+10,inf=1e18;
long long w[N],k[N];
struct node{
    int v;
    long long w;
};
vector<node>g[10*N],a;
int id[N][22];
long long dis[10*N];
bitset<10*N>vis;
void dijkstra(int s){
    for(int i=1;i<=tot;i++){
        dis[i]=inf;vis[i]=0;
    }
    dis[s]=0;
    pq<pii,vector<pii>,greater<pii> >q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto r:g[u]){
            int v=r.v,w=r.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>o>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    tot=m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a.resize(k[i]+10);
        for(int j=1;j<=k[i];j++){
            int x,t;cin>>x>>t;
            a[j]=(node){x,t};
            id[x][i]=++tot;
            g[x].push_back({tot,t});
            g[tot].push_back({x,t});
        }
        for(int j=1;j<=k[i];j++){
            int x=a[j].v,t=a[j].w;
            if(j>1)g[id[x][i]].push_back({id[a[j-1].v][i],0});
            if(j<k[i])g[id[x][i]].push_back({id[a[j+1].v][i],0});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
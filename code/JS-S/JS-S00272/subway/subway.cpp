#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=528,M=1e6+16;
int cnt,w[M],to[M],nxt[M],val[M],h[N];
ll ans[N];
void add(int u,int v,int w){
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
struct qry{
    int u,v,id;
}a[N];
bitset<N>dij,vis;
ll dis[N];
struct node{
    int u;
    ll w;
    friend bool operator<(const node &x,const node &y){
        return x.w>y.w;
    }
};
void Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<node>q;
    q.push({s,0});
    vis.reset();
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i];
            if(dis[v]>dis[u]+val[i]){
                q.push({v,dis[v]=dis[u]+val[i]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1,u,v,t1,t2;j<=k;++j){
            cin>>v>>t2;
            if(j>1){
                int t=t1+t2;
                add(u,v,t);
                add(v,u,t);
            }
            t1=t2;
            u=v;
        }
    }
    for(int i=1;i<=q;++i){
        cin>>a[i].u>>a[i].v;
        a[i].id=i;
    }
    sort(a+1,a+1+q,[](const qry &x,const qry &y){
        return x.u<y.u;
    });
    for(int i=1;i<=q;++i){
        if(!dij[a[i].u]){
            Dijkstra(a[i].u);
            dij[a[i].u]=1;
        }
        ans[a[i].id]=dis[a[i].v]+w[a[i].u]+w[a[i].v];
    }
    for(int i=1;i<=q;++i){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
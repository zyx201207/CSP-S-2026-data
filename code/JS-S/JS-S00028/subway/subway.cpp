#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=505,maxm=5e5+50,maxq=1e5+50,INF=1e18;
struct edge{
    ll v,w;
    bool operator<(const edge &A)const{
        return w>A.w;
    }
};
ll c,n,m,d,Q;
ll dis[maxn],vis[maxn],k[maxn];
ll w[maxm];
vector<edge>G[maxm];
vector<edge>T[maxm];
ll lk[maxn][maxn];
ll ans[maxq],x[maxq],y[maxq];
priority_queue<edge>q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)lk[i][j]=INF;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            G[a].push_back((edge){i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i].size();j++){
            for(int k=j+1;k<G[i].size();k++){
                lk[G[i][j].v][G[i][k].v]=min(lk[G[i][j].v][G[i][k].v],G[i][j].w+G[i][k].w);
                lk[G[i][k].v][G[i][j].v]=lk[G[i][j].v][G[i][k].v];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(lk[i][j]!=INF){
                T[i].push_back((edge){j,lk[i][j]});
            }
        }
    }
    for(int i=1;i<=Q;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=Q;i++){
        for(int j=1;j<=n;j++){
            dis[j]=INF;
            vis[j]=0;
        }
        for(int j=0;j<G[x[i]].size();j++){
            dis[G[x[i]][j].v]=w[x[i]]+G[x[i]][j].w;
            q.push((edge){G[x[i]][j].v,dis[G[x[i]][j].v]});
        }
        while(!q.empty()){
            ll u=q.top().v;
            q.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto e:T[u]){
                ll v=e.v,w=e.w;
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    q.push((edge){v,dis[v]});
                }
            }
        }
        ll ans=INF;
        for(int j=0;j<G[y[i]].size();j++){
            ans=min(ans,dis[G[y[i]][j].v]+G[y[i]][j].w+w[y[i]]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll> 
#define fi first
#define se second
#define pb push_back
const ll N=1e6+10,inf=1e18;
ll c,n,m,d,q,k,w[N],x[N],y[N],xx,yy,dis[N],ans[N];
bool vis[N];
vector<pii> e[N];
void add(ll x,ll y,ll z){
    e[x].pb({y,z});
    e[y].pb({x,z});
}
void dijkstra(ll s){
    priority_queue<pii> q;
    for(int i=1;i<=m+n;i++) vis[i]=0,dis[i]=inf;
    dis[s]=w[s];
    q.push({-dis[s],s});
    while(!q.empty()){
        ll x=q.top().se;q.pop();
        if(vis[x]) continue;vis[x]=1;
        for(auto pp:e[x]){
            ll y=pp.fi,w=pp.se;
            if(dis[y]>dis[x]+w){
                dis[y]=dis[x]+w;
                q.push({-dis[y],y});
            }
        }
    }
}
vector<pii> Q[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // ll st=clock();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>x[j]>>y[j];
        for(int j=1;j<=k;j++) add(x[j],m+i,y[j]);
    }
    for(int i=1;i<=q;i++){
        cin>>xx>>yy;
        if(xx>yy) swap(xx,yy);
        Q[xx].pb({yy,i});
    }
    for(int i=1;i<=m;i++)
        if(Q[i].size()){
            dijkstra(i);
            for(auto pp:Q[i]){
                ll y=pp.fi,id=pp.se;
                ans[id]=dis[y]+w[y];
            }
        }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    // ll ed=clock();cerr<<(double)(ed-st)/CLOCKS_PER_SEC;
    return 0;
}
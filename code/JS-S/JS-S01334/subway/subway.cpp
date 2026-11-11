#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
vector<PII> g[1000505];
vector<ll> s[500005];
ll w[500005];
ll k[505];
ll dis[1000505];
bool vis[1000505];
ll c,n,m,d,q;
ll S;

void dij(ll x,ll y){
    for(ll i=1;i<=S;i++){
        dis[i]=2e18;vis[i]=0;
    }
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push({0,x});
    dis[x]=0;
    while(q.size()){
        PII p=q.top();
        q.pop();
        int u=p.second;
        if(u==y){
            cout<<dis[u]+w[x]+w[y]<<"\n";
            return;
        }
        if(vis[u])continue;
        vis[u]=true;
        for(PII ne : g[u]){
            int v=ne.first,w=ne.second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    int T;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll kk;cin>>kk;
        for(ll j=1;j<=kk;j++){
            ll a,t;cin>>a>>t;
            T=max(T,t);
            g[m+n+k[i-1]+j].push_back({a,t});
            g[a].push_back({m+n+k[i-1]+j,t});
            g[m+i].push_back({m+n+k[i-1]+j,0});
            g[m+n+k[i-1]+j].push_back({m+i,0});
        }
        k[i]=k[i-1]+kk;
    }
    S=n+m+k[n];
    while(q--){
        ll x,y;cin>>x>>y;
        if(c<=19)dij(x,y);
        //else if(c<=19)cout<<2*T+w[x]+w[y]<<"\n";
        else cout<<w[x]+w[y]<<"\n";
    }
    return 0;
}
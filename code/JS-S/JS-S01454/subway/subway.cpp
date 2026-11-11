#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{ll v,w;};
int w[500050];
ll dis[550][550],del=500000;
vector<node> g[500550];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;++i) cin>>w[i];
    for(ll i=1;i<=n;++i){
        ll k; cin>>k;
        for(ll j=1;j<=k;++j){
            ll a,t; cin>>a>>t;
            g[i+del].push_back({a,t});
            g[a].push_back({i+del,t});
        }
    }
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j){
            dis[i][j]=1e18;
        }
    }
    for(ll i=1;i<=n;++i) dis[i][i]=0;
    for(ll i=1;i<=m;++i){
        for(ll j=0;j<g[i].size();++j){
            for(ll k=j+1;k<g[i].size();++k){
                ll l=g[i][j].v-del,r=g[i][k].v-del;
                dis[l][r]=dis[r][l]=min(dis[l][r],g[i][j].w+g[i][k].w);
            }
        }
    }
    for(ll k=1;k<=n;++k){
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(ll i=1;i<=q;++i){
        ll x,y,ans=1e18; cin>>x>>y;
        for(ll j=0;j<g[x].size();++j){
            for(ll k=0;k<g[y].size();++k){
                ll l=g[x][j].v-del,r=g[y][k].v-del;
                ans=min(ans,g[x][j].w+g[y][k].w+dis[l][r]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

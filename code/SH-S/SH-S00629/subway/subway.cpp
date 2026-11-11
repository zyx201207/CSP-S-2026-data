#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d;
ll sz;
ll a[500005];
vector<pair<ll,ll>> g[1005005];
priority_queue<pair<ll,ll>> q;
ll dis[1005005];
ll vis[1005005];
ll ans[1005][1005];
void work(ll s){
    for(ll i=1;i<=sz;i++)dis[i]=1e18,vis[i]=0;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto now=q.top();
        q.pop();
        ll u=now.second;
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(v.second+dis[u]<dis[v.first]){
                dis[v.first]=dis[u]+v.second;
                q.push({-dis[v.first],v.first});
            }
        }
    }
}
void work2(ll s){
    for(ll i=1;i<=sz;i++)dis[i]=1e18,vis[i]=0;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto now=q.top();
        q.pop();
        ll u=now.second;
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(v.second+dis[u]<dis[v.first]){
                dis[v.first]=dis[u]+v.second;
                q.push({-dis[v.first],v.first});
            }
        }
    }
    for(ll i=1;i<=m;i++){
        ans[s][i]=dis[i];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t;
    cin>>c>>n>>m>>d>>t;
    sz=m;
    for(ll i=1;i<=m;i++){
        cin>>a[i];
    }
    ll pre=0;
    ll mn=1e18;
    for(ll i=1;i<=n;i++){
        ll tmp=0;
        cin>>tmp;
        pre=0;
        while(tmp--){
            ll x,y;
            cin>>x>>y;
            sz++;
            g[x].push_back({sz,y});
            g[sz].push_back({x,y});
            if(pre)g[pre].push_back({sz,0}),g[sz].push_back({pre,0});
            pre=sz;
        }
    }
    if(c>=9&&c<=11){
        for(ll i=1;i<=m;i++){
            work2(i);
        }
        while(t--){
            ll x,y;
            cin>>x>>y;
            cout<<ans[x][y]+a[x]+a[y]<<"\n";
        }
        return 0;
    }
    for(ll i=1;i<=t;i++){
        ll x,y;
        cin>>x>>y;
        work(x);
        cout<<dis[y]+a[x]+a[y]<<"\n";
    }
}
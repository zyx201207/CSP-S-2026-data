#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[600000];
ll dj(ll s,ll e,vector<vector<pair<ll,ll>>>& adj){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    memset(vis,false,sizeof(vis));
    pq.push({0,s});
    while(!pq.empty()){
        pair<ll,ll> u = pq.top();
        pq.pop();
        if(vis[u.second])continue;
        if(u.second == e)return u.first;
        vis[u.second] = true;
        for(pair<ll,ll> v : adj[u.second]){
            pq.push({u.first+v.first,v.second});
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    vector<ll> w(m+1);
    for(ll i = 1;i<=m;i++){
        cin >> w[i];
    }
    vector<vector<pair<ll,ll>>> adj(n+m+1);
    for(ll i = 1;i<=n;i++){
        ll k;
        cin >> k;
        for(ll j = 0;j<k;j++){
            ll a,t;
            cin >> a >> t;
            adj[m+i].push_back({t,a});
            adj[a].push_back({t,m+i});
        }
    }
    while(q--){
        ll x,y;
        cin >> x >> y;
        ll u = dj(x,y,adj);
        cout << u+w[x]+w[y] << "\n";
    }
    return 0;
}

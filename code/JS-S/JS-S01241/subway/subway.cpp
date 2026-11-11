#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
struct ia{
    ll to,id,val;
};
struct mk{
    ll id,lzt;
};
ll c,n,m,d,q,w[500005];
vector <ia> tu[500505];
void bfs(ll u,ll v){
    vector <ll> dis(m + 5,0);
    bool vis[500005];
    memset(vis,0,sizeof(vis));
    queue<mk> q;
    dis[u] = 0;
    q.push({u,0});
    ll lid = 0;
    for (auto i : tu[u]){
        q.push({i.to,i.id});
        lid = u;
        dis[i.to] = dis[u] + i.val;
    }
    q.pop();
    while (!q.empty()){
        mk a = q.front();q.pop();
        if (vis[a.id]) continue;
        vis[a.id]= true;
        for (auto i : tu[a.id]){
            if (a.lzt == i.id){
                dis[i.id] = dis[a.id];
                q.push({i.to,i.id});
            }
            else{
                dis[i.id] = dis[a.id] + 2 * i.val;
                q.push({i.to,i.id});
            }
        }
    }cout << dis[v] + w[u] + w[v] << "\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (re i = 1;i <= m;i++) cin >> w[i];
    for (re i = 1;i <= n;i++){
        ll k;cin >> k;
        ll la = 0,lav = 0;
        for (re j = 1;j <= k;j++){
            ll a,t;cin >> a >> t;
            if (j == 1){
                la = a;
                lav = t;
            }
            else{
                tu[la].push_back({a,i,lav});
                tu[a].push_back({la,i,t});
                la = a;lav = t;
            }
        }
    }
    for (re i = 1;i <= q;i++){
        ll u,v;cin >> u >> v;
        bfs(u,v);
    }
    return 0;
}

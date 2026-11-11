// [52,70]
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const int Q = 1e5 + 5;
int n,m,d,q,w[N];
vector<pair<int,int>> tmp,ve[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool vis[M];
int dis[M];
struct query{
    int u,v;
}qry[Q];
void dijk(int st){
    for(int i = 1;i <= m;i++){
        dis[i] = 1e18;
        vis[i] = 0;
    }
    pq.push({0,st});
    dis[st] = 0;
    while(!pq.empty()){
        auto [du,u] = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v,w] : ve[u]){
            if(dis[v] > du + w){
                dis[v] = du + w;
                pq.push({dis[v],v});
            }
        }
    }
}
int dist[1005][1005];
void solve(){
    int tid; cin >> tid >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        tmp.clear();
        int k; cin >> k;
        for(int j = 1;j <= k;j++){
            int a,t; cin >> a >> t;
            tmp.pb({a,t});
        }
        for(auto [u,w1] : tmp){
            for(auto [v,w2] : tmp){
                if(u != v){
                    ve[u].pb({v,w1 + w2});
                    ve[v].pb({u,w1 + w2});
                }
            }
        }
    }
    if(tid >= 9 && tid <= 11){
        set<int> se;
        for(int i = 1;i <= q;i++){
            int u,v; cin >> u >> v;
            se.insert(u);
            se.insert(v);
            qry[i] = {u,v};
        }
        for(auto i : se){
            dijk(i);
            for(auto j : se) dist[i][j] = dis[j];
        }
        for(int i = 1;i <= q;i++){
            int u = qry[i].u,v = qry[i].v;
            cout << dist[u][v] + w[u] + w[v] << "\n";
        }
        return;
    }
    for(int i = 1;i <= q;i++){
        int u,v; cin >> u >> v;
        dijk(u);
        cout << w[u] + w[v] + dis[v] << "\n";
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
    return 0;
}
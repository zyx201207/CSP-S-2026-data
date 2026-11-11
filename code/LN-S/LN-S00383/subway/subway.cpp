#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    struct Node{
        int v;
        ll weight;
    };
    vector<ll> w(m + 1);
    for(int i = 1;i <= m;i++) cin>>w[i];
    vector<vector<int>> a(n + 1);
    vector<vector<ll>> t(n + 1);
    vector<ll> k(n + 1);
    for(int i = 1;i <= n;i++){
        cin>>k[i];
        a[i].resize(k[i] + 1);
        t[i].resize(k[i] + 1);
        for(int j = 1;j <= k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    vector<vector<Node>> G(m + n + 1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k[i];j++){
            G[i + m].push_back({a[i][j],t[i][j]});
            G[a[i][j]].push_back({i + m,t[i][j]});
        }
    }
    vector<vector<ll>> dis(m + n + 1,vector<ll>(m + n + 1,LLONG_MAX / 3));
    auto dijkstra = [&](int s) -> void {
        vector<int> vis(n + m + 1);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        dis[s][s] = (ll)0;
        pq.push({0,s});
        while(!pq.empty()){
            pair<ll,int> tmp = pq.top();
            pq.pop();
            int u = tmp.second;
            if(vis[u]) continue;
            vis[u] = 1;
            for(Node tmp : G[u]){
                int v = tmp.v;
                ll wei = tmp.weight;
                if(dis[s][v] > dis[s][u] + wei){
                    dis[s][v] = dis[s][u] + wei;
                    pq.push({dis[s][v],v});
                }
            }
        }
    };
    for(int i = 1;i <= m;i++){
        // cout<<i<<'\n';
        dijkstra(i);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<dis[l][r] + w[l] + w[r]<<'\n';
    }
    return 0;
}
// g++ subway.cpp -o subway -std=c++14
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;

int c,n,m,d,q;
vector<ll> w;
vector<vector<pair<int, int>>> g;
ll dijkstra(int s,int t,int total_node){
    vector<ll> dis(total_node+1,INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    dis[s]=0;
    pq.emplace(0,s);
    while(!pq.empty()){
        auto[d, u]=pq.top();
        pq.pop();
        if(u==t){
            return d;
        }
        if(d>dis[u]){
            continue;
        }
        for(auto[v, ww]:g[u]){
            if(dis[v]>d+ww){
                dis[v]=d+ww;
                pq.emplace(dis[v],v);
            }
        }
    }
    return INF;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    w.resize(m+1);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int total_node=m+n;
    g.resize(total_node+1);
    for(int i=1;i<=n;i++){
        int vid=m+i;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[a].emplace_back(vid,t);
            g[vid].emplace_back(a,t);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll d =dijkstra(x,y,total_node);
        ll ans=w[x]+d+w[y];
        cout<<ans<< '\n';
    }
    return 0;
}

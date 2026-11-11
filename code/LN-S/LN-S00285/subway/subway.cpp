#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,x,y;
int k,a;
ll w[M],t;
vector<pair<int,ll>> g[N+M];
ll dijkstra(int s,int t){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dis(n+m+10,inf);
    dis[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        auto tp=pq.top();pq.pop();
        int u=tp.second;
        ll cd=tp.first;
        if(dis[u]!=cd)continue;
        for(auto d:g[u]){
            int v=d.first;
            ll c=d.second;
            if(dis[u]+c<dis[v]){
                dis[v]=dis[u]+c;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
    return dis[t];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k;
        while(k--){
            cin >> a >> t;
            g[n+a].push_back(make_pair(i,t));
            g[i].push_back(make_pair(n+a,t));
        }
    }
    while(q--){
        cin >> x >> y;
        cout << w[x]+w[y]+dijkstra(n+x,n+y) << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
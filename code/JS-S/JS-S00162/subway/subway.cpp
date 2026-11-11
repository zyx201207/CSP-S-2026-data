#include<bits/stdc++.h>
#define int long long
using namespace std;


struct node{
    int to, w;
    bool operator<(const node &other)const{
        return w > other.w;
    }
};
const int N = 505, M = 5e5+5, INF = LLONG_MAX;
int c, n, m, d, q;
int dis[M];
bool vis[M];

int w[M], a[N][N], t[N][N], stat[M]; 
vector<node> g[M+N+5];
priority_queue<node> pq;

void dijkstra(int s){
    for(int i=1; i<=m+n+1; i++) vis[i] = 0;
    for(int i=1; i<=m+n+1; i++){
        dis[i] = INF;
    }
    dis[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()){
        node x = pq.top();
        pq.pop();
        int u = x.to;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto i : g[u]){
            int v = i.to;
            if(dis[v] > dis[u] + i.w){
                dis[v] = dis[u] + i.w;
                pq.push({v, dis[v]});
            }
        }
    }
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        for(int j=1; j<=k; j++){
            cin >> a[i][j] >> t[i][j];
            g[m+i].push_back({a[i][j], t[i][j]});
            g[a[i][j]].push_back({m+i, t[i][j]});
        }
    }
    //dijkstra(1);
    //cout << dis[2] << '\n';
    while(q--){
        int x, y;
        cin >> x >> y;
        dijkstra(x);
        cout << dis[y] + w[x] + w[y] << '\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
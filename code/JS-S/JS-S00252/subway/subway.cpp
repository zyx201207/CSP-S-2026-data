#include<bits/stdc++.h>
#define int long long
using namespace std;

struct edge{
    int v;
    int w;
};

struct node{
    int u;
    int d;
};

bool operator>(const node& x, const node& y){
    return x.d > y.d;
}

const int N = 510;
const int M = 500010;

int c, n, m, d, q;
int t[M];
vector <edge> g[M+N];
vector <edge> G[N];
int vis[N];
int dist[N];
vector <int> ansdist[N];

void dijkstria(int s){
    priority_queue <node, vector <node>, greater <node> > q;
    dist[s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int u = it.u;
        int d = it.d;
        if (vis[u] == 1) continue;
        if (d > dist[u]) continue;
        vis[u] = 1;
        for (auto its : G[u]){
            int v = its.v;
            int w = its.w;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        ansdist[s].push_back(dist[i]);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++){
            int v, w;
            cin >> v >> w;
            g[i].push_back({v+n, w});
            g[v+n].push_back({i, w});
        }
    }

    for (int u = n+1; u <= n+m; u++){
        for (auto it1 : g[u]){
            for (auto it2 : g[u]){
                int v1 = it1.v;
                int v2 = it2.v;
                int w1 = it1.w;
                int w2 = it2.w;
                if (v1 != v2){
                    G[v1].push_back({v2, w1+w2});
                    G[v2].push_back({v1, w1+w2});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[j] = 1e18;
            vis[j] = 0;
        }
        dijkstria(i);
    }

    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        x += n;
        y += n;
        int ans = 1e18;
        for (auto it1 : g[x]){
            for (auto it2 : g[y]){
                int v1 = it1.v;
                int v2 = it2.v;
                int w1 = it1.w;
                int w2 = it2.w;
                int disti = w1+w2 + ansdist[v1][v2-1] + t[x-n]+t[y-n];
                ans = min(ans, disti);
            }
        }
        cout << ans << '\n';
    }

    //for (int i = 1; i <= n+m; i++){
    //    for (auto j : g[i]){
    //        cout << i << " " << j.v << " "  << j.w << '\n';
       // }
    //}

    return 0;
}

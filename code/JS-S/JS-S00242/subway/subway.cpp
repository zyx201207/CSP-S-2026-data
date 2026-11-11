#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 5e5+100;
const int N = 505;
int c, n, m, d, q, w[M];

namespace SMALL {
struct Node {
    ll first, second;
    friend bool operator< (const Node a, const Node b){
        return a.first > b.first;
    }
};
const int M = 2005;
const int Q = 1e5+100;
vector<pii> e[M];
ll dist[M];
bool vis[M];
struct Query{
    int x, y;
    int id;
    friend bool operator<(const Query a, const Query b){
        return a.x < b.x;
    }
};
ll ans[Q];
Query query[Q];
void addEdge(int u, int v, int w){
    e[u].push_back({v, w});
}
void dijkstra(int t){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[t] = 0;
    priority_queue<Node> pq;
    pq.push({0, t});
    while(!pq.empty()){
        Node top = pq.top();
        pq.pop();
        ll u = top.second;
        //cout << "VIS " << u << " " << vis[u] << endl;
        if (vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < e[u].size(); i++){
            ll v = e[u][i].first;
            ll w = e[u][i].second;
            //cout << "TOBE " << v << ": " << dist[v] << " with " << w << ": " << dist[u] << "+" << w << endl;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void main(){
    int k;
    for(int i = 1; i <= n; i++){
        cin >> k;
        m++;
        int tgt = m;
        for(int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            addEdge(a, tgt, t);
            addEdge(tgt, a, t);
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        if (x > y){
            swap(x, y);
        }
        query[i].id = i;
        query[i].x = x;
        query[i].y = y;
    }
    sort(query+1, query+q+1);
    int la = 0;
    for(int i = 1; i <= q; i++){
        int x = query[i].x, y = query[i].y;
        if (la != x){
            la = x;
            dijkstra(la);
        }
        ans[query[i].id] = w[x] + w[y] + dist[y];
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << endl;
    }
    return;
}
} // SMALL

namespace CASEB{
const int M = 2e4+10;
vector<int> e[M];
int dist[M];
bool vis[M];
void addEdge(int u, int v){
    e[u].push_back(v);
}
void bfs(int t){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < e[u].size(); i++){
            int v = e[u][i];
            if (vis[v]) continue;
            q.push(v);
            dist[v] = dist[u] + 1;
        }
    }
}
void main()
{
    int k, T;
    for(int i = 1; i <= n; i++){
        cin >> k;
        m++;
        int tgt = m;
        for(int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            T = t;
            addEdge(a, tgt);
            addEdge(tgt, a);
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        bfs(x);
        cout << 1ll * dist[y] * T + w[x] + w[y] << endl;
    }
}
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }

    if (c <= 11){
        SMALL::main();
        return 0;
    }
    if (c >= 12 && c <= 19){
        CASEB::main();
        return 0;
    }
}

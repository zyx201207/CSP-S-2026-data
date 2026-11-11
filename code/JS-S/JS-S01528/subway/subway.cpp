#include <bits/stdc++.h>
using namespace std;
constexpr int N = 6e5 + 3, M = 1.2e6 + 3;
long long c, n, m, d, q, h[N], ne[M], e[M], idx, w[M], dtp[N], did, x, y, dist[N], sk;
bool vis[M];
inline void add(int u, int v, long long wt){
    ne[idx] = h[u], e[idx] = v, w[idx] = wt, h[u] = idx++;
}
long long calc(){
    memset(dist, 0x3f, sizeof(dist));
    dist[x] = 0;
    for(int i = 1; i < sk + 2 * m; i++){
        queue<int> q;
        memset(vis, 0, sizeof(vis));
        q.push(x);
        vis[x] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = true;
            for(int i = h[u]; ~i; i = ne[i]){
                int v = e[i];
                if(dtp[v] == -1 && v != y){
                    continue;
                }
                dist[v] = min(dist[v], dist[u] + w[i]);
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
    }
    return dist[y];
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(h, -1, sizeof(h));
    did = 2 * m + 1;
    for(long long i = 1, wt; i <= m; i++){
        cin >> wt;
        dtp[i] = -1;
        dtp[i + m] = -2;
        add(i, i + m, wt);
        add(i + m, i, wt);
    }
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        sk += k;
        for(long long j = 0, a, t; j < k; j++){
            cin >> a >> t;
            dtp[i] = -3;
            add(a + m, i + 2 * m, t);
            add(i + 2 * m, a + m, t);
        }
    }
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        cout << calc() << '\n';
    }
    return 0;
}
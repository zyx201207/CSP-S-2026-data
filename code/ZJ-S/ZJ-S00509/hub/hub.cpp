#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int __c, n, k, p[N];
vector <int> g[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int x, int y){
    int px = find(x), py = find(y);
    if (px != py) p[px] = py;
}
bool check(int msk){
    iota(p, p + n, 0);
    for (int i = 0; i < n; i ++ ){
        if ((msk >> i) & 1){
            for (auto j : g[i]){
                if ((msk >> j) & 1){
                    merge(i, j);
                }
            }
        }
    }
    
    set <int> s;
    for (int i = 0; i < n; i ++ ){
        if ((msk >> i) & 1) s.insert(find(i));
    }
    if (s.size() > 2) return false;
    return true;
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) g[i].clear();
    for (int i = 1; i < n; i ++ ){
        int u, v; cin >> u >> v;
        u --, v -- ;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 1000000;
    for (int msk = 0; msk < (1 << n); msk ++ ){
        if (__builtin_popcount(msk) != k) continue;
        if (!check(msk)) continue;

        vector <int> dis(n, -1);
        queue <int> q;
        for (int i = 0; i < n; i ++ ){
            if ((msk >> i) & 1) dis[i] = 0, q.push(i);
        }
        while (q.size()){
            int u = q.front(); q.pop();
            for (auto v : g[u]){
                if (dis[v] == -1) dis[v] = dis[u] + 1, q.push(v);
            }
        }
        ans = min(ans, *max_element(dis.begin(), dis.end()));
    }
    cout << ans << "\n";
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> __c;

    int T; cin >> T;
    while (T -- ) solve();
}
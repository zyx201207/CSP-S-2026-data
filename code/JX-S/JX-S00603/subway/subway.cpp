#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 5e5 + 10, D = 25;
int op, n, m, d, k, q, x, y;
int w[M], dis[N][N], st[N];
vector<pair<int, int>> e[N];
void spfa(int s){
    queue<int> q;
    dis[s][s] = 0;
    st[s] = 1;
    q.push(s);
    while (q.size()){
        int u = q.front();
        q.pop();
        st[u] = 0;
        for (auto t : e[u]){
            int v = t.first, ww = t.second;
            if (dis[s][v] > dis[s][u] + ww){
                dis[s][v] = dis[v][s] = dis[s][u] + ww;
                if (!st[v]){
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> op >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k;
        vector<int> a, t;
        for (int j = 1; j <= k; j++){
            int u, v;
            cin >> u >> v;
            a.push_back(u);
            t.push_back(v);
        }
        for (int j = 0; j < k; j++){
            for (int l = j + 1; l < k; l++){
                int u = a[j], v = a[l];
                int tt = t[j] + t[l];
                e[u].push_back({v, tt});
                e[v].push_back({u, tt});
            }
            
        }
    }
    memset(dis, 0x3f3f3f3f, sizeof dis);
    for (int i = 1; i <= m; i++){
        memset(st, 0, sizeof st);
        spfa(i);
    }
    /*
    for (int i = 1; i <= m; i++){
        cout << e[i].size() << "\n";
        for (auto j : e[i]){
            cout << i << " " << j.first << " " << j.second << "\n";
        }
    }
    */
    while (q--){
        cin >> x >> y;
        int ans = w[x] + w[y] + dis[x][y];
        cout << ans << "\n";
    }
    return 0;
}
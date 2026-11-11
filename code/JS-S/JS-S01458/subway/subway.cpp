#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{ signed u, v, w, nxt; } e[10000];
signed head[20000], epos;
void add(int u, int v, int w) {
    e[++epos] = { u, v, w, head[u] };
    head[u] = epos;
}

int c, n, m, d, q;

int dijk(int st, int ed) {
    vector<int> dst(1000, 1000000000000000000ll);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dst[st] = 0;
    q.push({0, st});
    for (;q.size();) {
        auto tp = q.top();
        int d = tp.first, u = tp.second;
        //cout << u << endl;
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (d + w >= dst[v]) continue;
            dst[v] = d + w;
            q.push({d + w, v});
        }
    }
    return dst[ed];
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    vector<int> val(m + 1);
    for (int i = 1; i <= m; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) {
        int ki; cin >> ki;
        for (int j = 1, l = 0; j <= ki; j++) {
            int idx, d; cin >> idx >> d;
            add(idx, m + i, d);
            add(m + i, idx, d);
        }
    }
    //for (int i = 1; i <= epos; i++) cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << ' ' << e[i].nxt << endl;
    for (int u, v;q--;) {
        cin >> u >> v;
        cout << dijk(u, v) + val[u] + val[v] << endl;
    }
    return 0;
}
/*

10 3
0 3 6 7 8 9 10 11 14 17

*/

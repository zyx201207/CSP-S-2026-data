#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
std::vector<int> G[N];
int c, T, n, k, u[N], v[N], fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline int calc(int S) {
    iota(fa, fa + n, 0);
    for (int i = 1; i < n; i++) {
        if ((S >> u[i] & 1) && (S >> v[i] & 1)) {
            fa[find(u[i])] = find(v[i]);
        }
    }
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        if (S >> i & 1) st.insert(find(i));
    }
    if (st.size() > 2) return n;

    std::queue<int> Q;
    std::vector<int> dis(n, n);
    for (int i = 0; i < n; i++) {
        if (S >> i & 1) {
            dis[i] = 0, Q.push(i);
        }
    }
    for (int u; !Q.empty(); ) {
        u = Q.front(), Q.pop();
        for (auto &v : G[u]) {
            if (dis[v] == n) {
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
    }
    int ans = *max_element(dis.begin(), dis.end());
    return ans;
}
inline void solve(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i], u[i]--, v[i]--;
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    if (k == n) {
        cout << "0\n";
        return;
    }
    int ans = n;
    for (int S = 1; S < (1 << n); S++) {
        if (__builtin_popcount(S) == k) {
            ans = min(ans, calc(S));
        }
    }
    cout << ans << '\n';
}
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
int main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    cin >> c >> T; while (T--) solve();
	return 0;
}

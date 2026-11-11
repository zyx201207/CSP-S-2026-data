#include <bits/stdc++.h>

using namespace std;

int c, n, ans;
long long d;
vector<long long> pos;
vector<vector<int>> g;

inline void special1(long long dif) {
    if (dif > d) {
        cout << 0 << "\n";
        return;
    }

    int t = d / dif;
    for (int i = 3; i < n; i++) {
        if ((i + 1) / t == i / t + 1 && i / t + 1 == 2) {
            ans += n - i;
        }
    }

    cout << ans << "\n";
}

inline void bfs1(int s) {
    queue<int> que;
    que.push(s);

    vector<int> mndis(n + 1, INT_MAX);
    mndis[s] = 0;

    while (que.size()) {
        int u = que.front();
        que.pop();

        for (int v : g[u]) {
            if (mndis[u] + 1 < mndis[v]) {
                que.push(v);
                mndis[v] = mndis[u] + 1;
            }
        }
    }

    vector<int> dis(n + 1, INT_MAX);
    dis[s] = 0;

    vector<int> cnt(n + 1);

    que.push(s);
    while (que.size()) {
        int u = que.front();
        que.pop();
        
        for (int v : g[u]) {
            if (dis[v] == mndis[v] && dis[u] + 1 == dis[v]) {
                cnt[v]++;
                que.push(v);
            } else if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans += cnt[i] == 1;
    }
}

inline void common() {
    g.assign(n + 1, {});
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (pos[v] - pos[u] <= d) {
                g[u].push_back(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        bfs1(i);
    }

    cout << ans << "\n";
}

inline void solve() {
    cin >> n >> d;

    bool flag1 = true;
    long long dif;
    pos.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        if (i == 2) {
            dif = pos[i] - pos[i - 1];
        } else if (i > 2 && pos[i] - pos[i - 1] != dif) {
            flag1 = false;
        }
    }

    if (n <= 3 || pos[n] - pos[1] <= d) {
        cout << 0 << "\n";
        return;
    }
    
    ans = 0;
    if (flag1) {
        special1(dif);
    } else {
        common();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int t;
    cin >> c >> t;

    while (t--) {
        solve();
    }

    return 0;
}

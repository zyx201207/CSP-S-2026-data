#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<char> used;
vector<int> s, f, dis;

struct DSU {
    vector<int> f;
    int num;

    void init(int n, int k) {
        f.resize(n + 1);
        num = k;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }
    int findr(int u) {
        return f[u] = f[u] == u ? u : findr(f[u]);
    }
    void merge(int u, int v) {
        int ru = findr(u), rv = findr(v);
        if (ru != rv) {
            f[ru] = rv;
            num--;
        }
    }
} dsu;

int n, k, ans;

int bfs() {
    queue<int> q;
    dis.assign(n + 1, 2e9);

    for (int i = 1; i <= k; i++) {
        q.push(s[i]);
        dis[s[i]] = 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : tree[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dis[i]);
    }

    return mx;
}

void dfs(int num, int lst) {
    if (num == k + 1) {
        dsu.init(n, k);
        for (int i = 1; i <= k; i++) {
            if (used[f[i]]) {
                dsu.merge(i, f[i]);
            }
        }
        if (dsu.num <= 2) {
            ans = min(ans, bfs());
        }
        return;
    }

    for (int i = lst + 1; i <= n; i++) {
        used[i] = true;
        s[num] = i;
        dfs(num + 1, i);
        used[i] = false;
    }
}

void init_f(int u, int lst) {
    f[u] = lst;
    for (int v : tree[u]) {
        if (v == lst) continue;
        init_f(v, u);
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;

        used.assign(n + 1, false);
        s.assign(k + 1, 0);
        f.assign(n + 1, 0);
        tree.assign(n + 1, vector<int>());

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        ans = 2e9;
        init_f(1, 0);
        dfs(1, 0);

        cout << ans << "\n";
    }

    return 0;
}
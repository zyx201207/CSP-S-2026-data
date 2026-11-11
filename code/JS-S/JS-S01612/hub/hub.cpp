#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 7;

vector<int> g[N];


struct Node {
    int u, d;
};

bool vis1[N];
int vis2[N];
bool vis3[N];
int sum2;


int ans;
int res;
int ans_e;

queue<Node> q;

void dfs1(int u) {
    vis2[u] = sum2;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis1[v] || vis2[v]) continue;
        dfs1(v);
    }
}

int dfs2(int u, int d) {
    res = max(res, d);
    vis3[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (vis3[v]) continue;
        dfs2(v, d + 1);
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n + 3; i++) g[i].clear();

        ans_e = 0x3f3f3f3f;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }


        for (int i = 1; i <= (1 << n) - 1; i++) {
            memset(vis1, 0, sizeof vis1);
            memset(vis2, 0, sizeof vis2);
            memset(vis3, 0, sizeof vis3);
            g[n + 1].clear();
            int z = i, sum1 = 0;
            while (z) {
                if (z & 1) sum1++;
                z >>= 1;
            }
            if (sum1 != k) continue;
            z = i;
            int pos = 1;
            while (z) {
                if (z & 1) vis1[pos] = 1;
                z >>= 1;
                pos++;
            }
            sum2 = 0;
            for (int i = 1; i <= n; i++) {
                if (vis1[i] && !vis2[i]) {
                    sum2++;
                    dfs1(i);
                }
            }
            if (sum2 > 2) continue;

            for (int i = 1; i <= n; i++) {
                if (vis2[i]) {
                    vis3[i] = 1;
                    for (int j = 0; j < g[i].size(); j++) {
                        if (!vis2[g[i][j]])
                            g[n + 1].push_back(g[i][j]);
                    }
                }
            }
            ans = -1;

            q.push({n + 1, 0});
            while (!q.empty()) {
                Node node = q.front();
                q.pop();
                int u = node.u;
                if (vis3[u]) continue;
                int d = node.d;
                ans = max(ans, d);
                vis3[u] = 1;
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i];
                    if (vis3[v]) continue;
                    q.push({v, d + 1});
                }
            }
            ans_e = min(ans, ans_e);

        }
        cout << ans_e << "\n";
    }



    return 0;
}

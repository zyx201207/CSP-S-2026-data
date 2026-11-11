#include <bits/stdc++.h>
#define int long long
#define elif else if
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m);
    for (auto& i : w) cin >> i;
    vector<vector<int>> t(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int a, x;
            cin >> a >> x;
            t[i][a - 1] = x;
        }
    }

    struct question { int x, y; int id; };
    vector<question> que(q);
    for (int i = 0; i < q; ++i) {
        cin >> que[i].x >> que[i].y;
        que[i].id = i;
    }
    sort(que.begin(), que.end(), [](const question& ii, const question& jj) { return ii.x < jj.x; });

    struct answer { int val, id; };
    vector<answer> ans;
    for (int i = 0; i < q; ) {
        struct distance { int val, line; };
        vector<distance> dis(m);
        dis[que[i].x].val = 0;
        vector<int> res(m, INT_MAX);
        for (int l = 0; l < n; ++l) {
            dis[que[i].x].line = l;
            struct element { distance dis; int u; bool operator<(const element& _) { return dis.val < _.dis.val; }};
            priority_queue<element, vector<element>, greater<element>> pq;
            pq.push({ dis[que[i].x], que[i].x });
            vector<char> vis(m);
            while (not pq.empty()) {
                int u = pq.top().u;
                int line = pq.top().dis.line;
                pq.pop();
                vis[u] = 1;
                for (int v = 0; v < m; ++v) {
                    if (dis[u].val + t[line][v] + t[line][u] < dis[v].val) {
                        dis[v].val = dis[u].val + t[line][v] + t[line][u];
                        dis[v].line = line;
                    }
                    if (vis[v] == 0) pq.push({ dis[v], v });
                }
            }

            for (int j = 0; j < m; ++j)
                res[j] = min(res[j], dis[j].val + t[l][j] + t[l][que[i].x]);
        }
        do {
            ans.push_back({ res[que[i].y] + w[que[i].x] + w[que[i].y], que[i].id });
            i++;
        } while (i < q && que[i].x == que[i - 1].x);
    }
    sort(ans.begin(), ans.end(), [](const answer& ii, const answer& jj) { return ii.id < jj.id; });

    for (auto i : ans) cout << i.val << '\n';

    return 0;
}

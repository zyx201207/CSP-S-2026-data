#include<bits/stdc++.h>
#define int long long
#define node pair<int, pair<int, int> >//w  to   type
using namespace std;

int c, n, m, d, Q;
const int N = 5e5 + 10;
int w[N];
int k[505];
vector<node> v[N];
int t[N][505];
int dis[N], cnt[N];
bool vis[N];
priority_queue<node, vector<node>, greater<node> > q;

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> Q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        int lst = 0;
        for (int j = 1; j <= k[i]; j++) {
            int a;
            cin >> a;
            cin >> t[a][i];
            if (j != 1) {
                v[lst].push_back({0, {a, i}});
                v[a].push_back({0, {lst, i}});
            }
            lst = a;
        }
    }
    while (Q--) {
        int st, ed;
        cin >> st >> ed;
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, false, sizeof(vis));
        dis[st] = w[st] + w[ed];
        q.push({0, {st, 0}});
        int g = 1e9 + 10;
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            if (vis[x.second.first] && cnt[x.second.first] >= n) continue;
            vis[x.second.first] = true;
            if (cnt[x.second.first] < 0) cnt[x.second.first] = 0;
            if (x.second.first == ed) g = min(g, t[ed][x.second.second]);
            for (auto i : v[x.second.first]) {
                int w = i.first, to = i.second.first, type = i.second.second;
                if (type != x.second.second) w += t[x.second.first][type] + t[x.second.first][x.second.second];
                if (dis[to] > dis[x.second.first] + w) {
                    dis[to] = dis[x.second.first] + w;
                }
                cnt[to]++;
                q.push({dis[to], {to, type}});
            }
        }
        cout << dis[ed] + g << '\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

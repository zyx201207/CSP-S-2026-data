#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 1e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll w[N];
vector<pair<int, ll> > G[N];
ll dis[N];
bool vis[N];
struct Query {
    int st, ed;
} qs[100010];
ll ans[100010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, Q;
    cin >> c >> n >> m >> d >> Q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int x, v;
            cin >> x >> v;
            G[i + m].push_back({x, v});
            G[x].push_back({i + m, v});
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> qs[i].st >> qs[i].ed;
//        qs[i].st += m;
        ans[i] = INF;
    }
    priority_queue<pli, vector<pli>, greater<pli> > q;
    for (int i = 1; i <= n; i++) {
        int st = i + m;
        while (!q.empty()) q.pop();
        for (int j = 1; j <= n + m; j++) {
            dis[j] = INF;
            vis[j] = 0;
        }
        dis[st] = 0;
        q.push({0, st});
        while (!q.empty()) {
            int now = q.top().y;
            q.pop();
            if (vis[now]) continue;
            vis[now] = 1;
            for (int k = 0; k < G[now].size(); k++) {
                int v = G[now][k].x, w = G[now][k].y;
                if (dis[v] > dis[now] + w) {
                    dis[v] = dis[now] + w;
                    q.push({v, dis[v]});
                }
            }
        }
        for (int j = 0; j < Q; j++) ans[j] = min(ans[j], dis[qs[j].st] + dis[qs[j].ed]);
    }
    for (int i = 0; i < Q; i++) cout << ans[i] + w[qs[i].st] + w[qs[i].ed] << '\n';
    return 0;
}

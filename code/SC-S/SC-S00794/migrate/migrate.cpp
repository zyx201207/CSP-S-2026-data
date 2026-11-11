#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 10;
int n, D;
int x[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
int dis[N], cnt[N];

void dijkstra(int s) {
    q.emplace(0, s);
    dis[s] = 0;
    cnt[s] = 1;

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        for (int v = u + 1; v <= n; v++) {
            if (x[v] - x[u] > D) break;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                q.emplace(dis[v], v);
            } else if (dis[v] == dis[u] + 1) cnt[v] += cnt[u];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;

    while (t--) {
        cin >> n >> D;
        for (int i = 1; i <= n; i++) cin >> x[i];

        int ans = 0;
        for (int i = 1; i < n; i++) {
            memset(dis, inf, sizeof dis);
            memset(cnt, 0, sizeof cnt);
            q = priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > ();

            dijkstra(i);

            for (int j = 1; j <= n; j++)
                if (cnt[j] == 2)
                    ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}

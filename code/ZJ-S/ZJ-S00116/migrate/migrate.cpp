#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int testid, T, n, dist[2000010], cnt[2000010];
ll d, x[2000010];
vector<int> edges[2000010];

void bfs(int st) {
    queue<int> q;
    memset(dist, 127, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    dist[st] = 0;
    q.push(st);
    for (; !q.empty(); ) {
        auto x = q.front();
        q.pop();
        for (auto p : edges[x])
            if (dist[x] + 1 < dist[p]) {
                dist[p] = dist[x] + 1;
                cnt[p] = 1;
                q.push(p);
            }
            else if (dist[x] + 1 == dist[p]) {
                cnt[p]++;
                q.push(p);
            }
    }
}

void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (abs(x[i] - x[j]) <= d)
                edges[i].push_back(j);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = 1; j <= n; j++) {
            if (cnt[j] == 2)
                ans++;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        edges[i].clear();
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &testid, &T);
    for (; T--; )
        solve();
    return 0;
}

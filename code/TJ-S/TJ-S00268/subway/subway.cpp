#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int test, n, m, d, _, w[N];
ll dis[600005];
set<pair<ll, int>> q;
vector<pair<int, int>> e[600005];
ll solve(int s, int t) {
    for (int i = 1; i <= n + m; i++)
        dis[i] = 9e18;
    dis[s] = 0;
    q.clear();
    for (int i = 1; i <= n + m; i++)
        q.insert({dis[i], i});
    for (; ; ) {
        int x = q.begin()->second;
        q.erase(q.begin());
        if (x == t || dis[s] > 1e18)
            break;
        for (auto y : e[x]) {
            int to = y.first, v = y.second;
            if (dis[x] + v < dis[to]) {
                q.erase({dis[to], to});
                dis[to] = dis[x] + v;
                q.insert({dis[to], to});
            }
        }
    }
    return dis[t];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &test, &n, &m, &d, &_);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        int sz;
        scanf("%d", &sz);
        for (int j = 1; j <= sz; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back({m + i, y});
            e[m + i].push_back({x, y});
        }
    }
    for (; _--; ) {
        int s, t;
        scanf("%d%d", &s, &t);
        printf("%lld\n", solve(s, t) + w[s] + w[t]);
    }
}

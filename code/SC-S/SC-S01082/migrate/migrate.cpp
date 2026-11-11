#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fi first
#define se second
#define pb push_back
#define mod(x) (x -= x >= Q ? Q : 0)

using namespace std;

typedef long long ll;

struct IO {
    IO () {
        freopen("migrate.in", "r", stdin);
        freopen("migrate.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;

const int N = 2e6 + 5;
const int inf = 1e9 + 7;

int n, c;
ll d, x[N];
int f[N], g[N];
int dis[N], inq[N];
queue < int > q;
vector < int > G[N];

void bfs (int s) {
    for (int i = 1; i <= n; i++)
        dis[i] = inf, f[i] = 0;
    // puts("in f:");
    // for (int i = 1; i <= n; i++)
    //     printf("%d%c", f[i], " \n"[i == n]);
    dis[s] = 0, f[s] = 1;
    q.push(s), inq[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        // printf("u:%d f:%d\n", u, f[u]);
        for (int v : G[u]) {
            if (dis[v] > dis[u] + 1) {
                // printf("%d->%d\n", u, v);
                dis[v] = dis[u] + 1;
                f[v] = f[u];
                if (!inq[v])
                    q.push(v), inq[v] = 1;
            } else if (dis[v] == dis[u] + 1)
                f[v] += f[u];
        }
    }
}

void solve () {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    sort(x + 1, x + n + 1);
    if (c == 11 || c == 12) {
        ll cd = x[2] - x[1];
        if (d % cd == 0 && d / cd > 1)
            printf("%lld\n", max(0, n - (d / cd) * 2 + 1));
        else
            printf("0\n");
        return;
    }
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
        int r = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        int l = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
        for (int j = l; j <= r; j++)
            G[i].pb(j);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = i; j <= n; j++)
            if (f[j] == 2) ans++;
    }
    printf("%lld\n", ans);
}

int main () {
    // zyt
    int T;
    scanf("%d%d", &c, &T);
    while (T--) solve();
    return 0;
}
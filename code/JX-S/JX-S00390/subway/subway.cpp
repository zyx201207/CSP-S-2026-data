#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 5;
typedef long long ll;
int n, m, q; ll wi[MAXN];
vector<pair<int, ll> > g[MAXN];
ll dis[505][505];

void read() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> n >> m >> q >> q;
    for (int i = 1; i <= m; i ++) cin >> wi[i];
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if (i != j) dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
    for (int i = 1, x; i <= n; i ++) {
        int ki; cin >> ki;
        for (ll t; ki --; ) {
            cin >> x >> t;
            g[x].push_back({i, t});
        }
    } cerr << "read ok" << endl;
}

void asap() {
    for (int i = 1; i <= m; i ++) {
        for (auto [u, tu] : g[i])
        for (auto [v, tv] : g[i]) {
            dis[u][v] = min(dis[u][v], tu + tv);
            dis[v][u] = min(dis[u][v], tu + tv);
        }
    } for (int k = 1; k <= n; k ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    cerr << "asap ok" << endl;
}

int main() {
    read(); asap();
    for (int x, y; q --; ) {
        cin >> x >> y;
        ll ans = 0x3f3f3f3f3f3f3f3fll;
        for (auto [u, tu] : g[x])
        for (auto [v, tv] : g[y]) {
            ans = min(ans, tu + dis[u][v] + tv);
        } cout << ans + wi[x] + wi[y] << '\n';
    } return 0;
}

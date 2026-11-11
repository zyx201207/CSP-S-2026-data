#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long 
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 5.1e5 + 5, MR = 5e5 + 5;
int CID, n, m, d, q;
ll w[NR];
vector<pair<int, ll> > g[NR];
void solve() {
    cin >> CID >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++ i)
        cin >> w[i];
    for (int i = 1; i <= n; ++ i) {
        int c;
        cin >> c;
        while (c --) {
            int p;
            ll v;
            cin >> p >> v;
            g[i + m].emplace_back(p, v);
            g[p].emplace_back(i + m, v);
        }
    }
    if (CID <= 11) {
        m += n;
        vector<vector<ll> > dis;
        dis.resize(m + 5);
        for (int i = 1; i <= m; ++ i)
            dis[i].resize(m + 5); 
        auto dijk = [&](int s) -> void {
            for (int i = 1; i <= m; ++ i)
                dis[s][i] = 1e18;
            priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
            q.emplace(0, s);
            dis[s][s] = 0;
            while (!q.empty()) {
                int x = q.top().second;
                if (q.top().first != dis[s][x]) {
                    q.pop();
                    continue;
                }
//                cout << x << ' ' << dis[s][x] << endl;
                q.pop();
                for (const auto &i : g[x])
                    if (dis[s][i.first] > dis[s][x] + i.second) {
                        dis[s][i.first] = dis[s][x] + i.second;
//                        cout << ' ' << i.first << ' ' << dis[s][i.first] << endl;
                        q.emplace(dis[s][i.first], i.first);
                    }
            } 
        };
//        dijk(1);
        for (int i = 1; i <= m - n; ++ i)
            dijk(i); 
        while (q --) {
            int x, y;
            cin >> x >> y;
            cout << dis[x][y] + w[x] + w[y] << '\n';
        }
        return;
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0; 
}

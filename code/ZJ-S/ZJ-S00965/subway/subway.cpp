#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define ull unsigned long long
#define OPEN freopen ("subway.in", "r", stdin); freopen ("subway.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
using namespace std;
constexpr int N = 5e5 + 5;

int c, n, m, d, q;

vector <pair <int, ll> > a[N];
vector <pair <int, ll> > s[N];
ll dis[520][520], w[N], t[520][520];
constexpr ll inf = 1e18;
priority_queue <pair <ll, int> > qu;
bitset <520> vis;
void dij (int st) {
    F (i, 1, n) dis[st][i] = inf;
    dis[st][st] = 0;
    vis.reset ();
    qu.push (make_pair (0LL, st));
    while (! qu.empty ()) {
        auto u = qu.top (); qu.pop ();
        int now = u.second; ll d = - u.first;
        if (vis[now]) continue ;
        vis[now] = 1;
        F (i, 1, n) {
            if (now == i) continue; 
            if (d + t[now][i] < dis[st][i]) {
                dis[st][i] = d + t[now][i];
                qu.push (make_pair (- dis[st][i], i));
            }
        }
    }
}

int main () {
    OPEN
    IOS
    cin >> c >> n >> m >> d >> q;
    F (i, 1, m) cin >> w[i];
    F (i, 1, n) {
        int k; cin >> k;
        F (j, 1, k) {
            int a; ll t; cin >> a >> t; :: a[i].push_back (make_pair (a, t));
            s[a].push_back (make_pair (i, t));
        }
    }

    F (i, 1, n) F (j, 1, n) t[i][j] = inf;

    F (i, 1, m) {
        int di = s[i].size ();
        F (j, 0, di - 1) {
            int u = s[i][j].first; ll val1 = s[i][j].second;
            F (k, 0, di - 1) {
                int v = s[i][k].first; ll val2 = s[i][k].second;
                t[u][v] = min (t[u][v], val1 + val2);
            }
        }
    }

    // F (i, 1, n) {
    //     F (j, 1, n) cerr << t[i][j] << ' '; cerr << '\n';
    // }

    F (i, 1, n) dij (i);

    F (i, 1, q) {
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        int dx = s[x].size (), dy = s[y].size ();
        F (j, 0, dx - 1) F (k, 0, dy - 1) {
            int u = s[x][j].first, v = s[y][k].first;
            // cerr << u << ' ' << v << '\n';
            ans = min (ans, w[x] + w[y] + dis[u][v] + s[x][j].second + s[y][k].second);
        }
        cout << ans << '\n';
    }

    cerr << clock () << '\n';
    return 0;
}
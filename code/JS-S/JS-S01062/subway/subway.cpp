#include <bits/stdc++.h>
using namespace std;

#define FILENAME "subway"

#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define fod(i, a, b) for (int i = b; i >= a; i--)
#define rep(i, n) fo(i, 0, n - 1)
#define repd(i, n) fod(i, 0, n - 1)
#define Rep(i, n) fo(i, 1, n)
#define Repd(i, n) fod(i, 1, n)
#define all(a) a.begin(), a.end()

typedef vector<int> vi;
 
void solve() {
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    vi w(m);
    rep(i, m) cin >> w[i];

    vector<vector<pair<int, int> > > g(n + m);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int a, t;
            cin >> a >> t;
            a--;
            g[m + i].push_back({a, t});
            g[a].push_back({m + i, t});
        }
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        priority_queue<int, vector<int>, greater<int> > pq;
        vi dist(n + m + 1, 2e9);
        dist[l] = w[l] + w[r];
        pq.push(l);
        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();
            for (auto v : g[u]) {
                if (dist[v.first] > dist[u] + v.second) {
                    pq.push(v.first);
                    dist[v.first] = dist[u] + v.second;
                }
            }
        }
        cout << dist[r] << '\n';
    }
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--) solve();
}
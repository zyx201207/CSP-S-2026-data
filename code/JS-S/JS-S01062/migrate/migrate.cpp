#include <bits/stdc++.h>
using namespace std;

#define FILENAME "migrate"

#define fo(i, a, b) for (long long i = a; i <= b; i++)
#define fod(i, a, b) for (int i = b; i >= a; i--)
#define rep(i, n) fo(i, 0, n - 1)
#define repd(i, n) fod(i, 0, n - 1)
#define Rep(i, n) fo(i, 1, n)
#define Repd(i, n) fod(i, 1, n)
#define all(a) a.begin(), a.end()

bool bfs(int n, int d, vector<int>& a, int x, int y) {
    queue<int> q;
    q.push(x);
    vector<int> dist(n, 2e9);
    dist[x] = 0;
    bool flag = false;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == y) {
            if (!flag) flag = true;
            else  {
                if (dist[u] == dist[y]) return true;
            }
        }
        rep(i, n) {
            if (i == u) continue;
            if (abs(a[i] - a[u]) > d) continue;
            if (!flag)  {
                q.push(i);
                dist[i] = dist[u] + 1;
            }
        }
    }
    return false;
}
 
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n) {
        fo(j, i + 1, n - 1) {
            if (bfs(n, d, a, i, j)) ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c;
    cin >> c;
    int t = 1;
    cin >> t;
    while(t--) solve();
}
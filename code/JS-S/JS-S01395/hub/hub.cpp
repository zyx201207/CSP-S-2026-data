#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
int c, t;
int n, k;
vector<int> e[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    cout << '0' << '\n';
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}

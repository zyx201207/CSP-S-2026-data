#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E6 + 10;
int c, t, n, k, u, v;
vector <int> g[MAXN];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    return 0;
}

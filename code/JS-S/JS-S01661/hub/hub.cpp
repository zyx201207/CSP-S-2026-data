#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k;
vector<int> e[1000005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout << max(0LL, k - 1) << '\n';
    }
    return 0;
}

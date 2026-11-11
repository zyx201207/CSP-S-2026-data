#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> node;
typedef pair<int, int> pr;
const int INF = 1e9;
int c, t, n, k, u, v;
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i < n; i++)
            cin >> u >> v;
        cout << (k & 1 ? 2 : 1) << '\n';
    }
    return 0;
}
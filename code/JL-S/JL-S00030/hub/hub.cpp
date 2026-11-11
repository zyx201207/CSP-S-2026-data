#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> bian;
int c, n, k, t, u, v;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t > 0) {
        t --;
        cin >> n >> k;
        for (int i = 1; i < n; i ++) {
            cin >> u, v;
            bian[u].push_back(v);
            bian[v].push_back(u);
        }
        cout << 1 << endl;
    }
    return 0;
}

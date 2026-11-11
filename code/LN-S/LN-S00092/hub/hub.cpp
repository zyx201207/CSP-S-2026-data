#include <bits/std++.h>
using namespace std;
vector<int> a[1000004];
void solve() {

    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout << (n - 2) / 2 + (n - 3) / 2 <<endl;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c,t;
    cin > c >>t;
    while(t--)
        solve();
    return 0;
}

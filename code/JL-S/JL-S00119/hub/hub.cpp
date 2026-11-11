#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
        cin >> a >> b;
    cout << (n - 2 * k + 1) / 2 << '\n';
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int tag, t;
    cin >> tag >> t;
    while (t--)
        solve();
    return 0;
}

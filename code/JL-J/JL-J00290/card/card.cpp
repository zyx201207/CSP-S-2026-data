#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 1e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int a[N];

vector<int> ans(N);

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> a[i];
    }
    for (int i = m; i >= 1; --i) {
        cout << i << " ";
    }
    return ;
}

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

bitset<N> nw;

ll a[N];

int main() {
    ios::sync_with_stdio(false);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nw[i] = 1;
    }
    ll ans = 0;
    for (int i = 40; i >= 0; i--) {
        bitset<N> b;
        for (int j = 1; j <= n; j++) {
            if ((a[j] >> i) & 1) {
                b[j] = 1;
            } else {
                b[j] = 0;
            }
        }
        if ((nw & b).count() >= m) {
            ans |= (1ll << i);
            nw &= b;
        }
    }
    cout << ans << '\n';
    return 0;
}

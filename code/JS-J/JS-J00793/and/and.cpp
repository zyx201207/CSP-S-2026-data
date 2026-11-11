#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[200005];
int used[200005];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = (2LL << 40) - 1;
    for (int i = 1; i <= m; i++) {
        ll mx = 0, pos = 0;
        for (int j = 1; j <= n; j++) {
            if (used[j] == 1) continue;
            if (ans & a[j] > mx) {
                mx = ans & a[j];
                pos = j;
            }
        }
        if (mx == 0) {cout << 0; return 0; }
        ans = mx;
        used[pos] = 1;
    }
    cout << ans;
    return 0;
}
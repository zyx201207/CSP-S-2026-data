#include<bits/stdc++.h>
using namespace std;

void io() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

using ll = long long;

const ll MX = 5e5 + 10;
ll n, m, a[MX], b[MX];


int main() {
    
    io();
    
    cin >> n >> m;
    b[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = 2e12;
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + a[i];
    }
    ll ans = 1;
    for (ll h = 1, t; h <= n; ++h) {
        t = max(t, h);
        while (t + 1 <= n && a[t + 1] * (t + 1 - h + 1) - (b[t + 1] - b[h - 1]) <= m) {
            ++t;
        }
//        cout << h << ' ' << t << '\n';
        ans = max(ans, t - h + 1);
        if (t >= n) break;
    }
    cout << ans << endl;
    return 0;
}


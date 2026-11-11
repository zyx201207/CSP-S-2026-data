/*
Cute Chtholly.
*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rep(i, l, r) for(ll i = (l); i <= (r); i++)
#define per(i, r, l) for(ll i = (r); i >= (l); i--)
#define fo(i, n) rep(i, 1, n)
using ll = long long;
using pll = pair<ll, ll>;

const ll N = 5e5 + 5;
ll n, m, a[N], sum[N], ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    fo(i, n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    fo(i, n) {
        sum[i] = sum[i - 1] + a[i];   
    }
    for(ll i = 1, j = 0; i <= n; i++) {
        while(i * a[i] - sum[i] - j * a[i] + sum[j] > m && j < i) j++;
        ans = max(ans, i - j);
    }
    cout << ans;
    return 0;
}


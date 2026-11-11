#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pil pair<int, ll>
#define pb push_back
#define edl cout <<'\n';
#define debug cout << '*';
#define fi first
#define se second
const int N = 2e6+10;
ll a[N];
void solve() {
	int n;
	ll d;
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	ll t = a[2] - a[1];
	ll q = d/t;
	if (q>=2) cout << max(0*1ll, n-2*q+1) << '\n';
	else cout << 0 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >>t;
	while (t --) {
		solve();
	}
}

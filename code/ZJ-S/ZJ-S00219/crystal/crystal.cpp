#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N];
ll qz[N];
ll ans = 0;
bool ok(int mid) {
	ll xl = 1, xr = mid;
	while (xr <= n) {
		ll sum = (mid - 1) * a[xr] - (qz[xr - 1] - qz[xl - 1]);
		if (sum <= m) return true;
		xl++, xr++;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) qz[i] = qz[i - 1] + a[i];
	ll l = 1, r = n;
	while (l <= r) {
		int mid = l - (l - r) / 2;
//		cout << l << " " << r << " " << mid << '\n';
		if(ok(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, ans = 1;
long long m, a[500005], _cost;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	_cost = a[1];
	for (int l = 1, r = 1; l <= n; l++) {
		_cost -= a[r] - a[l - 1];
		while (_cost + (a[r + 1] - a[r]) * (r - l + 1) <= m && r < n) {
			_cost += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], b[N], ans;

int solve(int k) {
	int l = 1, r = k;

	while(l < r) {
		int mid = (l + r) / 2;

		if (b[k] - b[mid - 1] + m >= a[k] * (k - mid + 1)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return k - l + 1;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
		ans = max(ans, solve(i));
	}

	cout << ans;

	return 0;
}
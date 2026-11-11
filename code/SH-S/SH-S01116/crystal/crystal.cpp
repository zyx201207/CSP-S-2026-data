#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500010;
int n, m;
int a[N];

pair<bool, int> check(int x) {
	int sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (x - a[i] > m) return {false, 0};
		if (x >= a[i]) {
			sum += max(0LL, x - a[i]);
			cnt++;
		}
		if (sum > m) return {false, 0};
	}
	return {true, cnt};
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int l = -1e18, r = 1e18;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		pair<bool, int> result = check(mid);
		
		if (result.first) ans = max(ans, result.second), l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}


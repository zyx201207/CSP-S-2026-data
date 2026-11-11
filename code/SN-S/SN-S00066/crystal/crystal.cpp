#include <bits/stdc++.h>
using namespace std;

int64_t n, m;
vector<int64_t> a, pre;
vector<int64_t> dp;

int64_t sum(int64_t l, int64_t r) { // [l, r], O(1)
	return pre[r] - pre[l - 1];
}

int64_t calc_usage(int64_t l, int64_t r, int64_t t) { // [l, r], O(1)
	return (t * (r - l + 1)) - sum(l, r);
}

int64_t calc_mid(int64_t l, int64_t r) { // mid of [l, r]
	return ((r - l + 1) / 2) + l - 1;
}

int64_t inner_calc(int64_t l, int64_t r, int64_t t, int64_t extra) { // O(log n)
	int64_t u = calc_usage(l, r, t);
	if (u <= m) {
		return r - l + 1 + extra;
	}
	
	int64_t r2 = r;
	int64_t mid = calc_mid(l, r); // mid of [l, r]
	while (1) {
		u = calc_usage(mid + 1, r, t);
//		printf("Current: [%d, %d], mid: %d, total [%d, %d], t: %d, u: %d\n", mid + 1, r, mid, l, r, t, u);
		if (u == m) {
			return r - (mid + 1) + 1 + extra;
		} else {
			if (mid + 1 == r) {
				if (u <= m) {
					return 1 + extra;
				}
				break;
			} 
			if (u < m) { // To Left
				r2 = mid;
				mid = calc_mid(l, mid);
			} else { // To Right
				l = mid + 1;
				mid = calc_mid(mid + 1, r2);
			}
		}
		if (mid < l) {
			break;
		}
	}
	return extra;
}

int64_t calc(int64_t l, int64_t r, int64_t c, int64_t d) { // [l, r], t at (c, d], O(log n)
	if (c == d) {
		return inner_calc(l, r, d, 1);
	}
	int64_t ans = 0;
	for (int64_t i = c + 1; i <= d; i++){
		ans = max(ans, inner_calc(l, r, i, i == d));
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// 读入 
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	// 升序排序 
	sort(a.begin() + 1, a.end());
	// 构建前缀和
	pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	} 
	// 找( O(n log n) )
	dp.resize(n + 1); 
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], calc(1, i - 1, a[i-1], a[i]));
//		cout << i << ": " << ans << endl;
	} 
	cout << dp[n] << endl;
	return 0;
}


// SN-S00367 李天江 西安交通大学附属中学 
#include <bits/stdc++.h>

using namespace std;
int n;
int64_t m;
array<int64_t, 500005> a, sum;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a.begin() + 1, a.begin() + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i, v = i;
		while (l <= r) {
			const int mid = (l + r) >> 1;
			const int len = (i - mid + 1);
			
			if (a[i] * len - (sum[i] - sum[mid - 1]) <= m) {
				r = mid - 1;
				v = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - v + 1);
	}
	cout << ans;
	return 0;
}

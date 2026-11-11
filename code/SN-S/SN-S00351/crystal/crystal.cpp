// SN-S00351 杨益烜 西安交通大学附属中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int n, ans;
ll m, a[N], s[N];

int calc(ll v, int id) {
	int l = 1, r = id;
	while (l < r) {
		int mid = (l + r) >> 1;
		if ((1LL * (id - mid + 1) * v - (s[id] - s[mid - 1])) <= m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return id - l + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, calc(a[i], i));
	}
	cout << ans;
	return 0;
}

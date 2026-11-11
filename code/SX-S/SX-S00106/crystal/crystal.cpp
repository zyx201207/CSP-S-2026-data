#include <bits/stdc++.h>
using namespace std;
long long n, m, da;
long long a[500005];

long long check(int mi) {
	long long cnt = 0, ans = 0, mm = m;
	for (int i = mi; i >= 1; i--) {
		if ((a[i] != a[mi]) && (mm >= a[mi] - a[i])) {
			cnt += a[mi] - a[i];
			mm -= a[mi] - a[i];
			ans++;
		}
		if (a[i] == a[mi]) {
			ans++;
		}
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		da = max(da, check(i));
	}
	cout << da;
	return 0;
}

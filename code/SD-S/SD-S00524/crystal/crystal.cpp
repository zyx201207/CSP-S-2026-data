#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long d[N];
long long s[N], s2[N];
bool check(int mid) {
	for (int i = 1; i <= n - mid + 1; ++i) {
		int j = i + mid - 1;
		if ((s[j] - s[i]) - (i - 1) * (s2[j] - s2[i]) <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; ++i) {
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; ++i) {
		s[i] = s[i - 1] + d[i] * (i - 1);
		s2[i] = s2[i - 1] + d[i];
	}
	int l = 1, r = n, ans = 1, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
	
	return 0;
}

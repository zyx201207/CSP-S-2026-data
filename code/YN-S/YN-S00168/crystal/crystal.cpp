#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long  sum[N];
long long  cha[N];
long long  a[N];
int  n;
long long  m;
long long ans;

bool check(int x) {
	long long  q = 1e18;
	for (int i = x; i <= n; i++) {
		long long  s = 0;
		int cnt = 1;
		for (int j = i - x + 2; j <= i; j++) {
			s = s + (a[j] - a[j - 1]) * (cnt);
			cnt++;
		}
		q = min(q, s);
	}
	return q <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 0, r = n;
	while (l <= r) {
		int  mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;

	return 0;
}
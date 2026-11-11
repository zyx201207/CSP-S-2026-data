#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 6;
long long n, m;
long long l, r, mid;
long long a[N];
long long c[N];

bool check(long long x) {
	long long cnt = (x * a[x]) - c[x];
	for (int i = 1; i + x - 1 <= n; i++) {
		long long v = c[i + x - 1] - c[i - 1];
		cnt = min(cnt, (x * a[i + x - 1]) - v);
	}
	if (cnt > m) return 0;
	return 1;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + a[i];
	}
	l = 1, r = n;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}

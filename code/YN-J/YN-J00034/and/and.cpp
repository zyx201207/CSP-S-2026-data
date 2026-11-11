#include <bits/stdc++.h>
using namespace std;
long long a[200005], p[200005];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == n) {
		long long cnt = a[1];
		for (int i = 2; i <= n; i++) {
			cnt = cnt & a[i];
		}
		cout << cnt;
		return 0;
	}
	if (m == 1) {
		long long maxn = -1;
		for (int i = 1; i <= n; i++) {
			maxn = max(maxn, a[i]);
		}
		cout << maxn;
		return 0;
	}
	if (m == 2) {
		long long maxn = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	long long cnt = a[1];
	for (int i = 2; i <= m; i++) {
		cnt = cnt & a[i];
	}
	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, cnt;
long long m, a[500005];

bool check(int x) {
	long long y = a[x], ans = 0;
	for (int i = 1; i < x; i++) {
		ans += y - a[i];
		if (ans > m) {
			return 0;
		}
	}
	return 1;
}

int fen() {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int w = fen();
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[w])
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}

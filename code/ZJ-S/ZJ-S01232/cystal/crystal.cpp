#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5 + 6;
int n;
LL m, a[N], d[N];
LL sum[N], suf[N];
LL get(int i, int x) {
	return sum[i] - sum[i - x] - (suf[i] - suf[i - x]) * (i - x + 1);
}
bool check(int x) {
	for (int i = x; i <= n; ++i) {
		if (get(i, x) <= m) {
			return 1;
		} 
	}
	return 0;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		d[i] = a[i] - a[i - 1];
	}
	sum[1] = 0;
	for (int i = 2; i <= n; ++i) {
		sum[i] = sum[i - 1] + d[i - 1] * (i - 1);
		suf[i] = suf[i - 1] + d[i - 1]; 
	}
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << l - 2;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 

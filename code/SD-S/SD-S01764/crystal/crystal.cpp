#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 5e5 + 3;
int n, m, a[N], l, r, mid, b[N], sum[N];

int need(int x, int y) {
	return sum[y] - sum[x - 1] - b[y] * (y - x + 1);
} 

bool check(int mid) {
	for (int i = 1; i <= n - mid + 1; i++) {
		if (need(i, i + mid - 1) <= m) return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) b[i] = a[n] - a[i];
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	
	return 0;
} 

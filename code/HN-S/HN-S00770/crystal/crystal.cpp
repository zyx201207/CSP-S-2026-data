#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], pre[N];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		int j = i - x + 1;
		if (a[i] * x - (pre[i] - pre[j - 1]) <= m) return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int lt = -1, rt = n + 1;
	while (lt + 1 < rt) {
		int mid = (lt + rt) >> 1;
		if (check(mid)) lt = mid;
		else rt = mid;
	}
	cout << lt << endl;
	return 0;
}
/*
5 5
4 4 3 2 2
*/

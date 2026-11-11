#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, ans;
long long m, a[N], b[N], f[N], sum;

bool check() {
	int nd = a[2] - a[1];
	for (int i = 1; i < n; i++)
		if (a[i + 1] - a[i] != d)
			return false;
	return true;
}

void solve() {
	/*
	5 7
	1 3 5 7 9
	f[i] = i * (i - 1) * d / 2
	*/
	int d = a[2] - a[1];
	for (int i = 1; i <= n; i++)
		if (1LL * i * (i - 1) * d <= m * 2)
			ans = i;
	cout << ans << '\n';
}

bool ok(int x, int y) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == x)
			b[i] = 1 << 30, ++cnt;
		else {
			if (a[i] < x)
				b[i] = x - a[i];
			else
				b[i] = 1 << 30;
		}
	sort(b + 1, b + n + 1);
	int nd = 0;
	for (int i = 1; i <= n; i++) {
		nd += b[i], ++cnt;
		if (nd > m) return false;
		if (cnt == y) return true;
	}
	return false;
}

void solve2() {
	for (int i = -320; i <= 320; i++)
		for (int j = 1; j <= n; j++) 
			ans = max(ans, ok(i, j) * j);
	cout << ans << '\n';
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	if (check()) {
		solve();
		return 0;
	}
	sort(a + 1, a + n + 1);
	if (n <= 16 && m <= 1000) {
		solve2();
		return 0;
	}
	for (int i = 1; i <= n; i++) f[i] = abs((i - 1) * a[i] - sum), sum += a[i];
	for (int i = 1; i <= n; i++) 
		if (f[i] <= m) ans = i;
	cout << ans << '\n';
	return 0;
}
// 55 or 100 pts
// Father!!!

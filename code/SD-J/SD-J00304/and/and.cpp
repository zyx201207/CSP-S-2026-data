#include <iostream>

using namespace std;

int n, m, a[200010], ans;

inline void dfs(int i, int x, int sum) {
	if (i == n + 1) {
		if (sum == m)
			ans = max(ans, x);
		return;
	}
	if (sum == m)
		dfs(n + 1, x, sum);
	if (n - i + 1 - sum < m)
		return;
	dfs(i + 1, x, sum);
	if (sum == 0)
		x = a[i];
	dfs(i + 1, x & a[i], ++sum);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	bool ok = 1;
	for (int i = 1; i <= n && ok; i++)
		if (a[i] > 4)
			ok = 0;
	if (ok) {
		int cnt4 = 0, cnt3 = 0, cnt2 = 0,
		cnt1 = 0, cnt0 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				++cnt0;
			if (a[i] == 1)
				++cnt1;
			if (a[i] == 2)
				++cnt2;
			if (a[i] == 3)
				++cnt3;
			if (a[i] == 4)
				++cnt4;
		}
		if (cnt4 >= m)
			cout << "4\n";
		else if (cnt3 >= m)
			cout << "3\n";
		else if (cnt2 >= m)
			cout << "2\n";
		else if (cnt1 + cnt3 >= m)
			cout << "1\n";
		else
			cout << "0\n";
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans << '\n';
}

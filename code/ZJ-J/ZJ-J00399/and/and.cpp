#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, a[maxn], ans, num[maxn];
bool vis[maxn];
void dfs(int p) {
	if (p == m + 1) {
		int res = num[m];
		for (int i = 1; i <= m; i++)
			res &= num[i];
		ans = max(ans, res);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		vis[i] = 1, num[p] = a[i];
		dfs(p + 1);
		vis[i] = 0, num[p] = 0;
	}
}
void sub1_5() {
	dfs(1);
	cout << ans <<'\n';
}
void sub6() {
	sort(a + 1, a + n + 1);
	cout << a[m] << '\n';
}
void sub7() {
	int res = a[n];
	for (int i = 1; i <= n; i++)
		res &= a[i];
	cout << res <<'\n';
}
void sub8_10() {
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, a[i] &a[j]);
	cout << ans << '\n';
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20) {
		sub1_5();
	} else if (n <= 2000) {
		if (m == 1)sub6();
		else if (m == n)sub7();
		else if (m == 2)sub8_10(); 
	} else {
		sun1_5();
	}
	return 0;
}

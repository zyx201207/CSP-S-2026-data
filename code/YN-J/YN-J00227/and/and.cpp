#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
int ans;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for (int i = 2; i <= m; i++)
		ans = ans & a[i];
	cout << ans;
	return 0;
}
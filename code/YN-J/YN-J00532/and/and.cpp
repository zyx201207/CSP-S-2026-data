#include <bits/stdc++.h>
using namespace std;
int a[200002];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		max(ans = a[i] ^ a[i + 1], a[i + 1] ^ a[i + 2]);
	cout << ans;
	return 0;
}
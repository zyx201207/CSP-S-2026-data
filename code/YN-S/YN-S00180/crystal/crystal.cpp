#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans, cz;

bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1, j = 1; j <= n; j++) {
		cz += (j - i) * (a[j] - a[j - 1]);
		while (cz > m) {
			cz -= a[j] - a[i];
			i++;
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans;
	return 0;
}

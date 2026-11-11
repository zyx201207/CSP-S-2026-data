#include <bits/stdc++.h>
using namespace std;
int a[100010];
int c[100010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	int t = 1, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		c[i] = a[i] - a[i - 1];
	c[1] = 0;
	while (m >= ans + c[t + 1] *t) {
		ans = ans + c[t + 1] * t;
		t++;
	}
	cout << t;
	return 0;
}

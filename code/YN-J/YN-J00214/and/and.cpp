#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int maxx;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i - 1) {
			flg = 1;
		}
	}
	sort(a + 1, a + n + 1);
	if (m == 1)
		cout << a[n];
	else {
		if (flg)
			cout << n - m;
		else {
			cout << a[n - m + 1];
		}
	}
	return 0;
}

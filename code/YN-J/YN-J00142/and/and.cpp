#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[200005], num = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		num = 0;
		for (int j = i; j < i + m; j++) {
			num = a[j] & a[j + 1];
			if (ans < num) {
				ans = num;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
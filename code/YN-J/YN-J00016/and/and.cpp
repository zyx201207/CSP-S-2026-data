#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	long long n, m, a[200005], max = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i + j - 1]&a[i + j] > max) {
				max = a[i + j - 1] & a[i + j];
			}
		}
	}
	cout << max << endl;
	return 0;
}
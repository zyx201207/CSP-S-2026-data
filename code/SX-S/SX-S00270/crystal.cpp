#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, m2, cnt, a[100010];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i <= i; j++) {
			if (a[i] == a[j]) {
				cnt = a[i] + a[j];
			}
			a[i] = a[i] + 1;
			m2++;
			if (m2 > m) {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}

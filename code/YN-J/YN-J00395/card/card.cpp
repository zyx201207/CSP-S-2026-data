#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], bj[100005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= i; j++) {
			if (a[i] == a[j] && a[i] != 0 && a[j] != 0) {
				for (int k = j; k <= i; k++) {
					a[k] = 0;
//					cout << a[i] << a[j] << a[k] << ' ';
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j] == i) {
				bj[i]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (bj[i] > 0) {
			cout << bj[i] << ' ';
		}
	}
	return 0;
}
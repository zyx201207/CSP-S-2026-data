#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxn = -1e9;
	for (int i = n; i >= 2; i--) {
		int ma = m;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= ma) {
				a[j] = a[i]
				       ma -= a[i] - a[j];
			}
		}
		int ansx = 0;
		for (int k = 1; k <= n; k++) {
			if (a[k] == a[i]) {
				ansx++;
			}
		}
		maxn = max(maxn, ansx);
	}
	cout << maxn;
	return 0;
}
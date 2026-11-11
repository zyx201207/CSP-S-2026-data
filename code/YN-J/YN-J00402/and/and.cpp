#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int maxn = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 2; i <= n; i++) {
			a[i] = (a[i] & a[i - 1]);
		}
		maxn = a[n];
	}
	for (int i = 1; i <= n; i++) {
		if (m == 2) {
			for (int j = i + 1; j <= n; j++) {
				maxn = max((a[j] & a[i]), maxn);
			}
		} else {
			maxn = max(maxn, a[i]);
		}
	}
	cout << maxn;
	return 0;
}
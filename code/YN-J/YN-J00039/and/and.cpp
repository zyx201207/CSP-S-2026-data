#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxn = 0;
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				maxn = max(maxn, i & j);
			}
		}
	} else if (m == 1) {
		for (int i = 1; i <= n; i++) {
			maxn = max(maxn, a[i]);
		}
	} else if (m == n) {
		maxn = a[1] & a[2];
		for (int i = 3; i <= n; i++) {
			maxn = maxn & a[i];
		}
	}
	cout << maxn;
	return 0;
}

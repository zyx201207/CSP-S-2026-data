#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1000;
int n, m, f1;
int a[N], b[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 2 && a[i] < a[i - 1]) {
			f1 = 1;
		}
	}
	if (f1 == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				b[a[i]] = i;
			} else if (a[i] == a[i - 1]) {
				b[a[i - 1]]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << b[i] << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cout << i << ' ';
	}
	return 0;
}

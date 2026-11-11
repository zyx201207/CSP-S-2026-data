#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a[200000], x = 0;
	cin >> n >> m;
	long long mx = 0, h = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (m--) {
		int ma = -1e9;
		for (int i = 1; i <= n; i++) {
			if (a[i] > ma) {
				if (x != 0)
					a[x] = ma;
				ma = a[i];
				x = i;
				a[i] = -1e9;
			}
		}
		if (h == 0)
			h = ma;
		else
			h = h and ma;
	}
	cout << h;
	return 0;
}
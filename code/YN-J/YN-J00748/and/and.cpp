#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, maxx = INT_MIN, h = 2047;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) {
			h = h & a[i];
		}
		maxx = max(maxx, a[i]);
	}
	if (m == 1) {
		cout << maxx;
	} else if (m == n) {
		cout << h;
	} else if (m == 2) {
		maxx = INT_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != i) {
					maxx = max(a[i] & a[j], maxx);
				}
			}
		}
		cout << maxx;
	} else {
		cout << 0;
	}
	return 0;
}
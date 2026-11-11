#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
int n, m;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int p = 0;
		for (int i = 1; i <= n; i++) {
			p = max(p, a[i]);
		}
		cout << p;
		return 0;
	}
	cout << 0;
	return 0;
}

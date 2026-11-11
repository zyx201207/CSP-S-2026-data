#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a > maxn) {
			maxn = a;
		}
	}
	cout << maxn;
	return 0;

}
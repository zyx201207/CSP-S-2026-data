#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << i;
	}
	return 0;
}
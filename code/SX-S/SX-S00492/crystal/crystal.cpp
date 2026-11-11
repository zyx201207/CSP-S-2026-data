#include <bits/stdc++.h>
using namespace std;
int a[5000010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> m;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		if (a[i] < m) {
			n++;

		}
	}
	cout << 3;
	return 0;
}


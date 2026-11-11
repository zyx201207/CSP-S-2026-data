#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1";
		return 0;
	}
	if (m == 1) {
		cout << "1";
		return 0;
	}
	if (m == 2) {
		if (a[m] == 1)
			cout << n << " " << n - 1;
		else
			cout << n - 1 << " " << n;
		return 0;
	} else
		cout << n;
	int x = m - 1;
	while (x != 0) {
		cout << " " << m;
		x--;
	}
	return 0;
}


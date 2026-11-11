#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ai, ci, num = 0, a[10005];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ai >> ci;
		if (ci == c(i + 1)) {
			num += 1;
		}
		int m += ai;
		for (int j = ai; j <= ai + ai; j++) {
			a[j] = ci;
		}
	}
	int sum = m / 2;
	for (int i = 1; i <= m; i++) {
		if (a[i] == a[m - i]) {
			sum--;
		}
	}
	if (num == n) {
		cout << "0";
	} else {
		cout << sum;
	}
	return 0;
}
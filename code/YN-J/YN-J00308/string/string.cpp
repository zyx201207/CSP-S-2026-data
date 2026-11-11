#include <bits/stdc++.h>
using namespace std;
int n, sum, num, cnt;
string a, b;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i <= n - 1; i++) {

		int x;
		char y;
		cin >> x >> y;
		sum += x;
		b[i] = x;

		for (int j = sum; j >= num; j--) {

			a[j] = y;
		}

		num = sum;
	}

	for (int i = 1; i <= n; i++) {

		if (a[i] != a[i + 1] || a[i] != a[i + b[i + 1]] && a[i] != a[b[i + 1]]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[100005], cnt;
	string x, y, z;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
		cin >> z;
		y += z;
	}

	for (int i = 0; i < n; i++) {

		while (a[i] > 0) {
			x += y[i];
			a[i]--;
		}
	}

	for (int i = 0; i < n; i++) {

		int l, r;
		l = i;
		r = n - 1 - i;

		if (x[l] != x[r])
			cnt++;
	}

	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x[1000010], s, len, number;

int a(int u, int v) {
	if (x[v] - x[u] <= d) {
		len = 1;
		number = 1;
		return 0;
	}
	int len1, number1;
	for (int i = u; x[i] - x[u] <= d; i++) {
		a(i, v);
		if (len1 == 0) {
			len1 = len + 1;
			number1 = number;
		} else {
			if (len1 == len + 1) {
				number1 += number;
			}
			if (len1 > len + 1) {
				len1 = len + 1;
				number1 = number;
			}
		}
	}
	len = len1;
	number = number1;
	return 0;
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		s = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		for (int h = 1; h < n; h++) {
			for (int k = h + 1; k <= n; k++) {
				a(h, k);
				if (2 == number)
					s++;
			}
		}
		cout << s << endl;
	}
	return 0;
}
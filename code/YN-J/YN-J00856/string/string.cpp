#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, s = 0, m = 1;
	char b, q[10086], j[10086];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> b;
		s += a;
		for (int j = 1; j <= a; j++) {
			q[m] = b;
			m++;
		}
	}
	int t = 1;
	for (int i = s; i >= 1; i--) {
		j[t] = q[i];
		t++;
	}
	int w = 0;
	for (int i = 1; i <= s; i++) {
		if (j[i] != q[i]) {
			w++;
		}
	}
	if (w > 0) {
		w -= s / 2;
	}
	cout << w ;
	return 0;
}
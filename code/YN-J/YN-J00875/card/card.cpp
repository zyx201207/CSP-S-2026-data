#include <bits/stdc++.h>
using namespace std;
int a[1000001], b[1000001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int js = 1;
	int bb = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1;; i++) {
		if (js - 1 >= n) {
			break;
		}
		b[i] = a[i + (js - 1)];
		cnt++;
		if (b[i] == a[n]) {
			js++;
		}

		for (int j = 1; j < i; j++) {
			if ((b[j] == b[i] || bb == 1) && i != 1) {
				bb = 1;
				b[j] = 0;
			}
		}
		bb = 0;

	}
	for (int i = 1; i <= cnt; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int c[a + 1];
	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}
	int d = c[a / 2];
	int e[a / 2];
	//cout << d << ' ';
	int f = 0;
	for (int j = 0; j < a / 2; j++) {
		e[j] = d - c[j];
		f = f + e[j];
		//cout << f << ' ';
	}
	//cout << f << ' ';
	int g = 0;
	if (c[a / 2] == c[a / 2 + 1]) {
		g++;
		for (int j = 0; j < a / 2; j++) {
			if (c[a / 2 + 1 + j] == c[a / 2 + 2 + j]) {
				g++;
			}
		}

	}
	for (int i = 0; i < a / 2; i++) {
		if (f > b) {
			if (e[i] != 0) {
				f = f - e[i];
			} else {
				f = f - e[i + 1];
				g++;
			}

		}
		if (f <= b) {
			cout << (a + 1) / 2 - i + g;
			break;
		}
		cout << f
		     ;

	}

	return 0;
}
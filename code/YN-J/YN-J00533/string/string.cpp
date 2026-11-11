#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a, b, h = 0;
	char c;
	string d, g;
	cin >> a;
	long long e = 0;
	for (int i = 1; i <= a; i++) {
		cin >> b >> c;
		for (int j = 1; j <= b; j++) {
			d += c;
		}
		e += b;
	}
	long long f;
	f = e / 2;
	if (e % 2 == 0) {
		for (int i = 0; i < f; i++) {
			g[i] = d[i];
		}
		for (int i = 0; i < f; i++) {
			if (d[f + i] != g[i]) {
				d[f + i] = g[i];
				h++;
			}
		}
	} else {
		for (int i = 0; i < f; i++) {
			g[i] = d[i];
		}
		for (int i = 0; i < f; i++) {
			if (d[f + i + 1] != g[i]) {
				d[f + i + 1] = g[i];
				h++;
			}
		}
	}
	cout << h << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
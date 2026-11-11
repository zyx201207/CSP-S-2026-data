#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long n, s, x = 0, p = 0, z = 0;
	char y;
	char ci[1000000000], a[500000000], b[500000000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		for (int k = 0; k < s; k++) {
			ci[z] = y;
			z++;
		}
		x = x + s;
	}
	if (x % 2 == 0) {
		for (int a1 = 0; a1 < (x / 2); a1++) {
			a[a1] = ci[a1];
			b[a1] = ci[x - a1 - 1];
		}
		for (int b1 = 0; b1 < (x / 2); b1++) {
			if (a[b1] != b[b1]) {
				p++;
			}
		}
		cout << p;
	}
	if (x % 2 == 1) {
		z = 0;
		for (int a2 = 0; a2 < ((x - 1) / 2); a2++) {
			a[a2] = ci[a2];
			b[a2] = ci[x - a2 - 1];
		}
		for (int b2 = 0; b2 < ((x - 1) / 2); b2++) {
			if (a[b2] != b[b2]) {
				p++;
			}
		}
		cout << p;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
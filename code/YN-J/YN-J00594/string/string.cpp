#include <bits/stdc++.h>
using namespace std;
int n, s = 1, b = 0;
int a[200010];
char c[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b = b + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == c[i + 1]) {
			s = 0;
			b = b / 2;
		} else {
			if (b % 2 != 0) {
				b = b / 2;
				for (int j = 1; j <= b; j++) {
					if (c[i] == c[i + 1]) {
						s = 0;
					}
				}
			}
		}

	}

	for (int i = 1; i <= b; i++) {
		if (s == 0) {
			break;
		}
		if (c[i] != c[i + 1]) {
			s++;
			c[i + 1] = c[i];
		}
	}
	cout << s - 1;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
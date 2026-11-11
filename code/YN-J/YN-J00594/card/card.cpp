#include <bits/stdc++.h>
using namespace std;
int n, m, c = 0, j = 1;
int a[100010], b[100010], p[3];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card .out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = b[i];
	}
	for (int s = m; s >= 1; s--) {
		for (int i = s; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (b[i] == b[j]) {
					for (int k = 1; k <= j; k++) {
						b[i] = 0;
					}
				}
				p[i]++;
			}
		}

	}
	for (int i = 1; i <= 3; i++) {
		cout << p[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int h;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int d[n + m], b[n * n + 2 * n * m + m * m];
	for (int i = 1; i <= n + m; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n + m; i++) {
		for (int j = 1; j <= n + m; j++) {
			b[j + h] = d[j] & d[i + 1 + j];
		}
		h += n + m;
	}
	int maxx = -1;
	for (int i = 1; i <= n * n + 2 * n * m + m * m; i++) {
		if (maxx < b[i]) {
			maxx = b[i];
		}
	}
	cout << maxx;
}
#include <bits/stdc++.h>
using namespace std;
int a[200010], b[100010], c[200010];
int d[100010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int tg = 0;

		for (int j = i; j <= n; j++) {
			if (b[a[j]] > 0) {
				while (b[a[j]] > 0) {
					b[c[tg]]--;
					tg--;
				}
			}
			b[a[j]]++;
			tg++;
			c[tg] = a[j];
		}
		for (int j = 1; j <= tg; j++) {
			d[c[j]]++;
		}
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
	}
	for (int i = 1; i <= m; i++) {
		cout << d[i] << " ";
	}
	return 0;
}
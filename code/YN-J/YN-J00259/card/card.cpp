#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005], c[500005], d[500005];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		d[a[i]] = max(d[a[i]], (long long)i);
	}
	for (int i = 1; i <= m; i++) {
		memset(c, 0, sizeof(c));
		for (int j = i; j <= n; j++) {
			if (!c[a[j]]) {
				b[a[j]]++;
				c[a[j]] = 1;
			}
			j = d[a[j]];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
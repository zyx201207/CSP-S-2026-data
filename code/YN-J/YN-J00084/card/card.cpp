#include <bits/stdc++.h>
using namespace std;
int a[500010], lk[500010], la[300010], c[500010], ans[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (la[a[i]] == 0) {
			la[a[i]] = i;
		} else {
			lk[la[a[i]]] = i;
			la[a[i]] = i;
		}
		c[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n) {
			if (lk[j] == 0)
				j++;
			else {
				c[j]--;
				c[lk[j]]++;
				j = lk[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		c[i] += c[i - 1];
		ans[a[i]] += c[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
}
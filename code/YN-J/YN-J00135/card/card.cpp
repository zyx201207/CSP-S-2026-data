#include <bits/stdc++.h>
using namespace std;
int a[5001], ans[5001];
int v[3001], b[5001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n > 5000) {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i + 1]) {
				ans[a[i]] = i;
			}
		}
		ans[a[n]] = n;
	} else {
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			for (int j = i; j <= n; j++)
				b[j] = a[j];
			for (int j = i; j <= n; j++) {
				if (v[a[j]] > 0) {
					for (int k = v[a[j]]; k < j; k++) {
						b[k] = 0;
						v[a[k]] = 0;
					}
					v[a[j]] = j;
				} else {
					v[a[j]] = j;
				}
			}
			for (int j = i; j <= n; j++) {
				//cout << b[j] << " ";
				ans[b[j]] ++;
			}
			//cout << endl;
		}

	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
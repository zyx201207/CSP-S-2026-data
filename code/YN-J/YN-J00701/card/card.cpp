#include <bits/stdc++.h>
using namespace std;

int a[500010], cnt[300010], p[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int sl = n;
		for (int j = 1; j <= n; j++) {
			p[i] = a[i];
		}
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= j; k++) {
				if (a[k] == a[j] && k < j) {
					for (int l = k; l <= n - j + 1; l++) {
						p[l] = p[l + j - k];
						sl -= j - k;
					}
				}
				for (int l = 1; l <= sl; i++) {
					cnt[a[l]]++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i];
	}
	return 0;
}
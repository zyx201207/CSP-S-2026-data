#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
int n, m;
int a[MAXN + 7];
int tis[MAXN + 7];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tis[i] = a[i];
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << (n - i + 1) % 2 << '\n';
		}
		return 0;
	}
	
	for (int i = 1; i <= m; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < i; k++) {
				if (tis[k] == tis[j])
					for (int l = k; l < i; l++)
						tis[l] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (tis[i] == i) ans++;
		}
		cout << ans << ' ';
	}
	
	return 0;
}

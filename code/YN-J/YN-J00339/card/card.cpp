#include <bits/stdc++.h>
using namespace std;
int n, a[500010], m, ans[300010], x[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int end = 1;
	for (int i = 1; i <= n; i++) {
		end = 1;
		for (int j = i; j <= n; j++) {
			int f = 0;
			for (int k = 1; k < end; k++) {
				if (x[k] == a[j]) {
					end = k + 1;
					f = 1;
					break;
				}
			}
			if (f == 0) {
				x[end] = a[j];
				end++;
			}
		}
		for (int j = 1; j < end; j++) {
			ans[x[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
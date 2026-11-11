#include <bits/stdc++.h>
using namespace std;
int a[200005], ans[300005], b1[300005];
bool vis[200005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b1[j] = 0;
			vis[j] = 0;
		}
		for (int j = i; j <= n; j++) {
			if (b1[a[j]] > 0) {
				for (int k = i; k <= j; k++) {
					if (vis[k])
						continue;
					if (a[k] == a[j]) {
						for (int l = k; l < j; l++) {
							vis[l] = 1;
							b1[a[l]]--;
						}
						break;
					}
				}
			}
			b1[a[j]]++;
		}
		for (int i = 1; i <= m; i++) {
			if (b1[i] > 0)
				ans[i]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n, m;
long a[500005];
long tj[300005];

struct node {
	long long wz, bol;
} vis[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for (int j = i; j <= n; j++) {
			if (vis[a[j]].bol == 1) {
				for (int k = vis[a[j]].wz; k <= j; k++) {
					vis[a[k]].bol = 0;
				}
			}
			vis[a[j]].wz = j;
			vis[a[j]].bol = 1;
		}
		for (int j = 1; j <= n; j++) {
			if (vis[j].bol == 1) {
				tj[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << tj[i] << " ";
	}
	return 0;
}
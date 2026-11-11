#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], b[N], c[N], d[N];
int n, m;
bool vis[N];
vector<int>e;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	queue<int>q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				int x = cnt;
				for (int k = d[a[j]]; k <= cnt; k++) {
					//	c[k] = -1;
					vis[a[j]] = 0;
					x--;
				}
				cnt = x;
				d[a[j]] = cnt;
			}
			vis[a[j]] = 1;
		}
		for (int j = 1; j <= m; j++) {
			if (vis[j]) {
				b[j]++;
			}

		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
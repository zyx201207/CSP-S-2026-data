#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, a[N], m;
int num[N], cnt;
int ans[N];
int vis[N];
bool flag[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
//			if (flag[a[j]]) continue;
			if (!vis[a[j]]) {
				num[++cnt] = a[j];
				vis[a[j]] = cnt;
			} else {
				for (int k = vis[a[j]] + 1; k <= cnt; ++k) {
//					flag[num[k]] = 1;
					vis[num[k]] = 0, num[k] = 0;
				}
				cnt = vis[a[j]];
			}
		}
		for (int j = 1; j <= cnt; ++j) {
			++ans[num[j]];
		}
//		for (int j = 1; j <= cnt; ++j) {
//			cout << num[i] << ' ';
//		} 
//		cout << '\n';
		for (int j = 1; j <= cnt; ++j) {
			num[j] = 0;
		}
		for (int j = 1; j <= m; ++j) {
			vis[j] = 0;
			flag[j] = 0;
		}
		cnt = 0;
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1


*/


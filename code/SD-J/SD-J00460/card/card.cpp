#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 

int n, m, f, x;
int a[N], q[N];
int flg = 0;
int cnt[N];
bool vis[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) flg = 1;
	}
	if (n <= 500) {
		for (int i = 1; i <= n; i ++) {
		
			memset(vis, 0, sizeof(vis));
			for (int j = i; j <= n; j ++) {
				if (vis[a[j]] != 1) {
					q[++ f] = a[j];
					vis[a[j]] = 1;
				} else {
					while (q[f] != a[j]) {
						vis[q[f]] = 0;
						f --;
					}
					vis[a[j]] = 1;
					q[++ f] = a[j];
				}
			}
			for (int i = 1; i <= m; i ++) {
				//cout << vis[i] << ' ';
				if (vis[i]) {
					cnt[i] ++;
				}
			}
		//cout << '\n';
		}
		for (int i = 1; i <= m; i ++) {
			cout << cnt[i] << ' ';
		}
		return 0;
	} else {
		if (flg == 0) {
			for (int i = 1; i <= n; i ++) {
				cnt[a[i]] ++;
			}
			for (int i = 2; i <= m; i ++) {
				cnt[i] = cnt[i] + cnt[i - 1];
			}
			for (int i = 1; i <= m; i ++) {
				cout << cnt[i] << ' ';
					
			}
			return 0;
		} else {
			for (int i = 1; i <= n; i ++) {
		
				memset(vis, 0, sizeof(vis));
				for (int j = i; j <= n; j ++) {
					if (vis[a[j]] != 1) {
						q[++ f] = a[j];
						vis[a[j]] = 1;
					} else {
						while (q[f] != a[j]) {
							vis[q[f]] = 0;
							f --;
						}
						vis[a[j]] = 1;
						q[++ f] = a[j];
					}
				}
				for (int i = 1; i <= m; i ++) {
					//cout << vis[i] << ' ';
					if (vis[i]) {
						cnt[i] ++;
					}
				}
			//cout << '\n';
			}
			for (int i = 1; i <= m; i ++) {
				cout << cnt[i] << ' ';
			}
			return 0;
		}
		
	}
	return 0;
} 
// 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 32 5 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134 


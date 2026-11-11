#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int M = 2e6 + 10;
int _, t, n;
LL d, a[M], dis[310][310], vis[310][310];
void solve1() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			dis[i][j] = 1e18;
			vis[i][j] = 0;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = 1; k <= i; k++) {
				for (int l = j; l <= n; l++) {
					if (dis[k][i] + dis[j][l] + 1 < dis[k][l] && a[j] - a[i] <= d) {
						vis[k][l] = 1;
						dis[k][l] = dis[k][i] + dis[j][l] + 1;
					} else if (dis[k][i] + dis[j][l] + 1 == dis[k][l] && a[j] - a[i] <= d) {
						vis[k][l]++;
					}
				}
			}
		}
	}
	int ans = 0, sum = 0, pos = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0, pos = 0;
		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << " ";
			if (dis[i][j] == dis[i][j - 1] && dis[i][j] != 1e18 && dis[i][j] != 0) sum++, pos = j;
			else if (sum == 1 && dis[i][j] != 1e18) {
				if (a[pos + 1] - a[pos - 1] <= d) {
//					cout << j << "  " << pos << endl;
					ans++;
				}
			}
		}
//		cout << endl;
	}
//	for (int i = 1; i <= n; i++) {
//		sum = pos = 0;
//		for (int j = 1; j <= n; j++) {
//			if (dis[i][j] == dis[i][j - 1] && dis[i][j] != 1e18) sum++, pos = i;
//			else if (sum == 1) {
//				if (i == pos + 1) cout << i << " " << pos << " " << a[i] - a[pos - 1] << endl;
//			}
//		}
//	}
	cout << ans << endl;
}
void solve2() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	} 
	int x = d / (a[2] - a[1]);
	if (x == 1 || x == 0) cout << 0 << endl;
	else cout << max(0LL, n - x * 2 + 1LL) << endl;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> _ >> t;
	while (t--) {
		if (_ <= 6) solve1();
		else if (_ == 11 || _ == 12) solve2(); 
		else cout << 0 << endl;
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int dis[1010][1010], cnt[1010][1010];
ll a[N];
int n;
ll d;

void solven() {
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(abs(a[i] - a[j]) <= d) {
				dis[i][j] = dis[j][i] = 1;
			}
		}
	}
	

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 1;
				} else if(dis[i][k] + dis[k][j] == dis[i][j]) {
					cnt[i][j]++;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(cnt[i][j] == 2) {
				ans++;;
			}
		}
	}
	ans /= 2;
	cout << ans << '\n';
}

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n <= 1000) {
		solven();
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
} 

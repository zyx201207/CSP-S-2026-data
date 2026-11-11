#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int n, d, a[N], ans, f[N][N];
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(f, 0, sizeof f);
	ans = 0;
//	for(int i = 1; i <= n; i++) {	
//		for(int j = i; j <= i + 1; j++) {
//			if(a[j] - a[i] > d) break;
//			f[i][j] = 1;
//		}
//	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(f[i][j]) continue;
			if(a[j] - a[i] <= d) {
				f[i][j] = 1;
				continue;
			}
			for(int k = j - 1; k >= i; k--) {
				if(a[j] - a[k] > d) break;
				f[i][j] += f[i][k];
//				cout << i << " " << j << " " << k << " " << f[i][k] <<endl;
			}
//			cout << i << " " << j << " " << f[i][j] <<endl;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
//			cout << f[i][j] << " ";
			if(f[i][j] == 2) ans++;
		}
//		cout << endl;
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

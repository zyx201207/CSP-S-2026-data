#include <bits/stdc++.h>
using namespace std;
//Trick||Treat!
//T3 1yanmiao
const int N = 2e5 + 10;
int b[N][35];
bool vis[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		for(int j = 0; j <= 30; j++) {
			b[i][j] = ((x >> j) & 1);
		}
	}
	int ans = 0;
	for(int j = 30; j >= 0; j--) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			cnt += b[i][j];
		}
		if(cnt >= m) {
			ans += (1 << j);
			for(int i = 1; i <= n; i++) {
				if(b[i][j] == 0) vis[i] = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

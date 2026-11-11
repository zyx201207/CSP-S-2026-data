#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int N = 5e3 + 9;

map <pair<int, int>, int> s;

int g[N][N];

int d[N];

int result;
int n, k;
int c, T;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> d[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				g[i][j] = 1e9;
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(abs(d[i] - d[j]) <= k) {
					g[i][j] = 1;
				}
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(g[i][k] + g[k][j] == g[i][j]) {
//						cout << i << " " << k << " " << j << endl;
						s[{i, j}]++;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(s[{i, j}] == 2) {
//					cout << i << " " << j << endl;
					result++;
				}
			}
		}
		cout << result / 2 << endl;
		result = 0;
		s.clear();
	}
	return 0;
}
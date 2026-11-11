#include <bits/stdc++.h>
using namespace std;

const int N = 2E3 + 10;
int c, t;
int n, d;
int dp[N][N];
bool g[N][N];
struct node {
	int pos, r;
} a[N];
int dfs(int x, int y, int m) {
	
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			a[i].pos = a[i].r = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i].pos;
		}
//		for (int i = 1; i <= n; i++)
		cout << 0 << endl;
//		for (int i = 1; i <= n; i++) {
//			int j = i;
//			while (j <= n && a[j] - a[i] <= d) {
//				j++;
//			}
//			a[i].r = j - 1;
//		}
//		for (int i = 1; i <= n ;i++) {
//			for (int j = i; j <= n; j++) {
//				if (a[j] - a[i] <= d) g[i][j] = true; 
//			}
//		}
//		for (int i = 1; i < n; i++) {
//			if (g[i][i + 1]) {
//				dp[i][i + 1] = 1;
//			} else dp[i][i + 1] = 0;
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 2; j <= n; j++) {
//				for (int k = i + 1; k <= j - 1; k++) {
//					if (dp[i][k] && dp[k][j])
//						dp[i][j] += dp[i][k] * dp[k][j];
//					else dp[i][j] = 0;
//				}
//			}
//		}
	
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 3; j <= n; j++) {
//				int npos = i + a[i].r;
//				int minpath = 1;
//				while (npos < j) {
//					npos += a[npos].r;
//					minpath++;
//				}
//				
//			}
//		}
	}
	
	return 0;
}

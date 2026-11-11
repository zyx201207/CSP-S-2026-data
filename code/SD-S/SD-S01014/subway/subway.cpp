#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
long long c, n, m, d, q, x, y, len, w[N], a[N][N], t[N][N], dp[N][N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= m; i++){
		cin >> w[i];
		dp[i][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		cin >> len;
		a[i][0] = t[i][0] = len;
		for(int j = 1; j <= len; j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j <= len; j++){
			for(int k = j; k <= len; k++){
				dp[a[i][j]][a[i][k]] = t[i][j] + t[i][k];
			}
		}
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while(q--){
		cin >> x >> y;
		cout << dp[min(x, y)][max(x, y)] + w[x] + w[y] << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, int>;
const int N = 4e3+5;
int op;
int x[N];
int lst[N];
int n, d;
vector<int>D[N];


int dp[N][N], cnt[N][N];


void solve() {
	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INT_MAX * (i != j);
			cnt[i][j] = 1;
		}
	}



	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
	}



	for (int i = 1; i <= n; i++) {
		lst[i] = lower_bound(x + i + 1, x + n + 1, x[i] + d) - x;
		for (int j = i + 1; j <= lst[i]; j++) {
			dp[i][j] = dp[j][i] = 1;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if ((dp[i][k] + dp[k][j] == dp[i][j])&&i!=k&&j!=k) {
					cnt[i][j]++;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += (cnt[i][j] == 2);
		}
	}

	cout << ans << endl;
}

int t_;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);

	t_ = 1;
	cin >> op >> t_;

	while (t_--) {
		solve();
	}

	cout.flush();

	return 0;
}

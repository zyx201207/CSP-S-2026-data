//#include<bits\stdc++.h>
#include<bits/stdc++.h>
//using namesoace std;
using namespace std;
/*====================*/
using lnt = long long;
using pii = pair<int, int>;
/*====================*/
const int INF = 0x3F3F3F3F;
const lnt LNF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
void Solve() {
	int n; lnt d; cin >> n >> d;
	
	vector<lnt> x(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i];
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 3; j <= n; j++) {
			bool flag = true;
			int cnt = 0, pos = i;
			vector<int> dp(n + 1); dp[i] = 1;
			while (pos < j) {
				int it = upper_bound(x.begin() + pos, x.end(), x[pos] + d) - x.begin() - 1;
				if (pos == it) {
					flag = false;
					break;
				}
				for (int k = pos; k < min(j, it); k++) dp[it] += dp[k];
				cnt++, pos = it;
			}
			if (flag) ans += (dp[j] == 2);
		}
	}
	
	cout << ans << '\n';
}

// int mian() {
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c; cin >> c;
	int T = 1; cin >> T;
	while (T--) Solve();
	return 0;
}

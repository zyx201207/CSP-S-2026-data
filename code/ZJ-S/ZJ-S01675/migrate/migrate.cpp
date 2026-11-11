#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define rp(i, a) for(int i = 1; i <= a; i++)
#define rd(i, a) for(int i = 0; i < a; i++)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = b; i >= a; i--)
#define vt vector
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e6 + 10;
const int M = 310;
int c, t, n, d, x[N];
pii dp[M];
vt<int> g[N];
void solve(int pos) {
	rep(i, pos, n) dp[i] = {n + 1, 0};
	dp[pos] = {0, 1};
	if(x[pos + 1] - x[pos] > d) return ;
	dp[pos + 1] = {1, 1};
	rep(i, pos + 2, n) {
		per(j, pos, i - 1) {
			if(x[i] - x[j] > d) break;
			if(dp[i].first > dp[j].first + 1) {
				dp[i] = {dp[j].first + 1, dp[j].second};
			} else if(dp[i].first == dp[j].first + 1) {
				dp[i].second += dp[j].second;
			}
		}
	}
	return ;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		rp(i, n) {
			cin >> x[i];
		}
		if(c == 11 || c == 12) {
			int step = x[2] - x[1];
			if(step > d) cout << "0" << endl;
			else if(d / step * 2 > n || d / step == 1) cout << "0" << endl;
			else cout << max(n - (d / step * 2) + 1, 1ll * 0) << endl;
			continue;
		} else if(c <= 10) {
			int ans = 0;
			rp(i, n - 1) {
				solve(i);
				rep(j, i + 1, n) {
					if(dp[j].second == 2) ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
/*
8 3
0 1 2 4 8 10 11 13
*/


#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=j;i<=k;i++)
#define dow(i, j, k) for(int i=j;i>=k;i--)
#define Suika 0
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n;
ll x[N], d;
int dp[N], cnt[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		rep(i, 1, n) cin >> x[i];
		//	cout << n << " " << d << "\n";
		ll ans = 0;
		if (n <= 100) {
			rep(i, 1, n) cnt[i] = 0;
			rep(i, 1, n) dp[i] = 1e9;
			rep(i, 1, n) {
				rep(j, i + 1, n) {
					dp[j] = 1e9, cnt[j] = 0;
				}
				dp[i] = 0; cnt[i] = 1;
				rep(j, i, n - 1) {
					rep(k, j + 1, n) {
						if (x[k] - x[j] > d) break;
						if (dp[j] + 1 < dp[k]) {
							cnt[k] = cnt[j]; dp[k] = dp[j] + 1;
						} else if (dp[j] + 1 == dp[k]) {
							cnt[k] += cnt[j]; 
						}
					}
				}
				rep(j, i + 1, n) {
					if (cnt[j] == 2) ans++;
				}
			}	
		} else {
			rep(i, 1, n) {
				rep(j, i + 1, n) {
					dp[j] = 1e9, cnt[j] = 0;
				}
				dp[i] = 0; cnt[i] = 1;
				vector<int> vec;
				dow(j, n, i + 1) vec.push_back(j);
				int r = 1;
				rep(j, i, n - 1) {
					while (r <= n && x[r] - x[j] <= d) r++;
					int len = vec.size();
					vector<int> vv;
					dow(k, len - 1, 0) {
						int v = vec[k];
						if (v >= r) break;
						if (dp[j] + 1 < dp[v]) {
							cnt[v] = cnt[j]; dp[v] = dp[j] + 1;
						} else if (dp[j] + 1 == dp[v]) {
							cnt[v] += cnt[j]; 
						}
						vv.push_back(v);
					}
					dow(k, len - 1, 0) {
						int v = vec[k];
						if (v >= r) break;
						vec.pop_back();
					}
					int len1 = vv.size();
					dow(k, len1 - 1, 0) {
						int v = vv[k];
						if (cnt[v] <= 2) vec.push_back(v);
					}
				}
				rep(j, i + 1, n) {
					if (cnt[j] == 2) ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return Suika;
}
/*
0 2
5 3
-2 -10 12
6 2
-4 -3 -2 -1 3 6

0 1
7 3
1 2 3 4 5 6 7
*/
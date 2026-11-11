#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 26;

int CaseID, t;

int n;
ll d;
ll x[MAXN];
int cntL[MAXN], cntR[MAXN];
ll sum[MAXN];

int dis[MAXN], cnt[MAXN];

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if(n == 1) {
		cout << "0\n";
		return;
	}
	if(CaseID == 11 || CaseID == 12) {
		ll c = x[2] - x[1];
		d = d / c;
		if(d < 2 || 2 * d - 1 > n) {
			cout << "0\n";
			return;
		}
		cout << n - (2 * d - 1) << '\n';
		return;
	}
	if(CaseID <= 10) {
		int ans = 0;
		for(int l = 1; l <= n; l++) {
			dis[l] = 0, cnt[l] = 1;
			for(int i = l + 1; i <= n; i++) {
				dis[i] = n + 1, cnt[i] = 0;
			}
			for(int i = l; i <= n; i++) {
				for(int nxt = i + 1; nxt <= n && x[nxt] <= x[i] + d; nxt++) {
					if(dis[i] + 1 < dis[nxt]) {
						dis[nxt] = dis[i] + 1;
						cnt[nxt] = cnt[i];
					} else if(dis[i] + 1 == dis[nxt]){
						cnt[nxt] += cnt[i];
					}
				}
				//cout << cnt[i] << ' ';
				ans += cnt[i] == 2;
			}
			//cout << '\n';
		}
		cout << ans << '\n';
		return;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		auto nxt = upper_bound(x + 1, x + 1 + n, x[i] + d) - 1;
		if(nxt <= x + i + 1)continue;
		int L = upper_bound(x + 1, x + 1 + n, *prev(prev(nxt)) + d) - x, R = upper_bound(x + 1, x + 1 + n, *prev(nxt) + d) - 1 - x;
		// cout << i << ' ' << L << ' ' << R << '\n';
		ans += (R - L + 1);
	}
	cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    for(cin >> CaseID >> t; t--; solve());
    return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/

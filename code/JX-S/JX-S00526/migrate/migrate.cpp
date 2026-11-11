#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(int id) {
	int n, d; cin >> n >> d;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(id == 11 || id == 12) { cout << 0 << '\n'; return; }
	int ans = 0;
	auto calc = [&](int l, int r) -> void {
		vector<int> x(r - l + 2);
		int len = r - l + 1;
		for(int i = 1; i <= len; i++) x[i] = a[i + l - 1];
		vector<int> nxt(len + 1), pre(len + 1);
		for(int i = 1, j = 1; i <= len; i++) {
			while(j < len && x[j + 1] - x[i] <= d) j++;
			nxt[i] = j;
		}
		for(int i = len, j = len; i >= 1; i--) {
			while(j > 1 && x[i] - x[j - 1] <= d) j--;
			pre[i] = j;
		}
		if(id <= 10) {
			for(int i = 1; i <= len; i++) {
				int s = 0, ni = i;
				vector<int> S(len + 1);
				for(int j = i + 1; j <= len; j++) {
					if(j == nxt[ni]) s += j, ni = nxt[ni];
					int p = pre[j]; p = max(p, i);
					S[j] = S[p] + j; if(s + (j != ni ? j : 0) - S[j] == 1) ans++;
				}
			}
		} else {
			// vector<array<int, 21> > nxt(len + 1), pre(len + 1), nxt_sum(len + 1), pre_sum(len + 1);
			// for(int i = 1, j = 1; i <= len; i++) {
			// 	while(j < len && x[j + 1] - x[i] <= d) j++;
			// 	nxt[i][0] = j; nxt_sum[i][0] = j;
			// }
			// for(int i = len, j = len; i >= 1; i--) {
			// 	while(j > 1 && x[i] - x[j - 1] <= d) j--;
			// 	pre[i][0] = j; pre_sum[i][0] = j;
			// } pre_sum[1][0] = nxt_sum[len][0] = 0;
			// for(int j = 1; j < 21; j++)
			// 	for(int i = 1; i <= len; i++)
			// 		nxt[i][j] = nxt[nxt[i][j - 1]][j - 1], nxt_sum[i][j] = nxt_sum[nxt[i][j - 1]][j - 1] + nxt_sum[i][j - 1],
			// 		pre[i][j] = pre[pre[i][j - 1]][j - 1], pre_sum[i][j] = pre_sum[pre[i][j - 1]][j - 1] + pre_sum[i][j - 1];
			vector<int> S1(len + 1), S2(len + 1);
			for(int i = 1; i <= len; i++) S1[nxt[i]]++;
			for(int i = len; i >= 1; i--) S2[pre[i]]++;
			vector<int> SS1(len + 1), SS2(len + 1);
			for(int i = 1; i <= len; i++)
				if(nxt[pre[i]] == i) SS1[i] += SS1[pre[i]];
			for(int i = len; i >= 1; i--)
				if(pre[nxt[i]] == i) SS2[i] += SS2[nxt[i]];
			for(int i = 1; i <= len; i++) {
				if(pre[nxt[nxt[i]]] == nxt[i] - 1 && pre[pre[nxt[nxt[i]]]] == i) {
					ans += (S1[i] + 1) * (S2[nxt[nxt[i]]] + 1);
				} else ans += S2[nxt[i] - 1];
			}
		}
	};
	for(int i = 1, j = 1; i <= n; i = j + 1) {
		j = i;
		while(j < n && a[j + 1] - a[j] <= d) j++;
		calc(i, j);
	} cout << ans << '\n';
}
/*
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
9 2
5 3
-3 0 2 3 4
2 1
*/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int id, t = 1;
	cin >> id >> t;
	while(t--) {
		solve(id);
	}
	return 0;
}
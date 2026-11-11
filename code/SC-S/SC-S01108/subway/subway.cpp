#include<bits/stdc++.h>
#define ll long long
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const ll N = 5e5+5;
ll k[5005], c, n, m, d, q, x[1000005], y[1000005];
ll w[N], ti[N];
ll F[5005][5005];
ll ans = 0;
vector<pair<ll, ll>> sta[N];
vector<ll> zhuanzhan[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	ll op1, op2;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> op1 >> op2;
			sta[op1].push_back({i, op2});
			ti[op1]++;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			F[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++) {
		F[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		if (ti[i] > 1) {
			for (auto u : sta[i]) {
				for (auto v : sta[i]) {
					F[u.first][v.first] = min(F[u.first][v.first], u.second + v.second);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (F[i][j] > F[i][k] + F[k][j]) {
					F[i][j] = F[i][k] + F[k][j];
					F[j][i] = F[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = w[x[i]] + w[y[i]];
		ll sum = 1e9;
		for (auto begin : sta[x[i]]) {
			for (auto end : sta[y[i]]) {
				sum = min(sum, F[begin.first][end.first] + begin.second + end.second);
			}
		}
		cout << ans + sum << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 114514200112231314;

ll c, n, m, d, q;
vector<vector<ll>> stid(539);
vector<vector<ll>> stdis(539);
vector<ll> stids(539);

ll ans = INF;
bool vis[503305];

void dfs(ll f, ll stn, ll lin, ll idx, ll tm) {
	if (stn = f) {
		ans = min(ans, tm);
		return;
	} if (vis[stn]) {
		return;
	} 
	vector<pair<ll, ll>> abl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < stids[i]; ++j) {
			if (stid[i][j] == stn) {
				abl.push_back({i, j});
			}
		}
	}
	if (abl.size() == 1) return;
	vis[stn] = true;
	for (int i = 0; i < abl.size(); ++i) {
		for (int j = 0; j < stids[abl[i].first]; ++j) {
			if (i != lin) dfs(f, stid[abl[i].first][j], abl[i].first, j
			, tm + stdis[lin][idx] + stdis[abl[i].first][abl[i].second]);
		}
	}
	vis[stn] = false;
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	vector<ll> w;
	w.push_back(0);
	for (ll i = 1; i <= m; ++i) {
		ll x; cin >> x;
		w.push_back(x);
	}
	for (ll i = 1; i <= n; ++i) {
		ll k; 
		cin >> k;
		stids[i] = k;
		for (ll j = 1; j <= k; ++j) {
			ll x, y; cin >> x >> y;
			stid[i].push_back(x);
			stdis[i].push_back(y);
		}
	}
	for (ll i = 1; i <= q; ++i) {
		ans = INF;
		ll s, f;
		cin >> s >> f;
		vector<pair<ll, ll>> abl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < stids[i]; ++j) {
				if (stid[i][j] == s) {
					abl.push_back({i, j});
				}
			}
		}
		vis[s] = true;
		for (int i = 0; i < abl.size(); ++i) {
			for (int j = 0; j < stids[abl[i].first]; ++j) {
				dfs(f, stid[abl[i].first][j], abl[i].first, j
				, stdis[abl[i].first][abl[i].second]);
			}
		}
		cout << ans + w[s] + w[f] << endl;
	}
	return 0;
}
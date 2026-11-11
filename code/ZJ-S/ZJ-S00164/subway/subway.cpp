/*
	Name: subway
	Copyright: CSP-S
	Author: CLP666
	Date: 31/10/26 17:50
	Description:
*/
#include <bits/stdc++.h>
#define rks register
using namespace std;
typedef long long ll;
const ll MAXN = 5e5+5;
//const ll MOD = ;
ll c, n, m, d, q;
ll w[MAXN];
map<ll, ll> LS[MAXN], SL[MAXN], LL[MAXN];
                                    
ll bfs(ll x, ll y) {
	ll dis[MAXN], ans = 1e9;
	memset(dis, -1, sizeof(dis));
	queue<pair<ll,ll>> que;
	if(LS[x][y])
		return LS[x][y];
	que.push({x, 0});
	while(!que.empty()) {
		auto tmp = que.front();
		que.pop();
		for(auto i : LL[tmp.first]) {
			if(!i.second)
				continue;
			if(dis[i.first] == -1 || tmp.second+i.second < dis[i.first]) {
				dis[i.first] = tmp.second+i.second;
				que.push({i.first, dis[i.first]});
			}
		}
	}
	for(auto i : SL[y]) {
		if(!i.second)
			continue;
		ans = min(ans, dis[i.first]+i.second);
	}
	return ans;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a, t, k, x, y, ans;
	cin >> c >> n >> m >> d >> q;
	for(rks ll i = 1; i <= m; i++)
		cin >> w[i];
	for(rks ll i = 1; i <= n; i++) {
		cin >> k;
		while(k--) {
			cin >> a >> t;
			LS[i][a] = t;
			for(auto j : SL[a]) {
				if(!j.second)
					continue;
				if(LL[i][j.first])
					LL[i][j.first] = LL[j.first][i] = min(LL[i][j.first],t+j.second);
				else
					LL[i][j.first] = LL[j.first][i] = t+j.second;
			}
			SL[a][i] = t;
		}
	}
	while(q--) {
		ans = 1e9;
		cin >> x >> y;
		for(auto i : SL[x]) {
			ans = min(ans, bfs(i.first, y)+i.second);
		}
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}


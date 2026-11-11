#include <bits/stdc++.h>
#define ll long long
#define il inline
#define pb push_back
using namespace std;
const ll N = 2e6+5, M = 2e5+5;

ll c, t, n, d, x[N];
ll l, r;
vector <ll> now;
bool vis[N];
ll mn, sum;
il bool kx() {
	for(ll i : now) cout << i << ' ';
	cout << "\n=====\n";
	if (x[0] - x[l] > d) return 0;
	for (int i = 1; i < now.size(); i++) {
		if (x[i] - x[i-1] > d) return 0;
	}
	ll last = now.size()-1;
	if (x[r] - x[last] > d) return 0;
	return 1;
}
ll way[N];

void dfs(ll s) {
	if (s > r) return;
	if (kx()) way[s]++;
	now.pb(s);
	dfs(s+1);
	now.pop_back();
	dfs(s+1);
}

il bool check() {
	now.clear();
//	cout << "checking: " <<l<<' '<<r<<'\n';
	dfs(l+1);
	for (int i = 1; i <= n; i++) cout << way[i] << ' ';
	cout << '\n';
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
//		if (c == 11 || c == 12) {

			ll bu =d/(x[2]-x[1]);
			if (bu > n) {
				cout << 0;
				continue;
			}
			ll zhou = 2 * bu - 1;
			if (zhou > n) {
				cout << 0;
				continue;
			}
			cout << (n-zhou>0 ? n-zhou : 0) << '\n';
//			continue;
//		}
//		ll ans = 0;
//		for (l = 1; l <= n; l++) {
//			for (r = l+1; r <= n; r++) {
//				if (check()) ans++;
//			}
//		}
//		cout << ans << '\n';
	}

	return 0;
}


/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5



*/
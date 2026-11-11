#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 509;
const ll inf = 1e18;
ll c, n, m, k, qq;
vector<pair<ll, ll>>e[N];
ll w[N];
ll vis[N];
ll diss[N][N];
ll ans;
void bfs(ll s) {
	queue<ll>q;
	for (ll i = 1; i <= n; i++) {
		diss[s][i] = inf;
	}
	diss[s][s] = 0;
	q.push(s);
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		ll u = it;
		for (auto [v, val] : e[u]) {
			if (diss[s][v] == inf) {
			} else {

				q.push(v);
				diss[s][v] = min(diss[s][v], diss[s][u] + val - w[v] + w[u]);
			}
		}
	}


}
int opt;
bool check(int mid){
	return opt++;
}
void solve() {
	cin >> n >> k;
	int l=1,r=1000000000;
	
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
}

int main() {
	cin >> c >> t;
	while (t--) {
		solve();
		cout << ans << endl;
	}
	return 0;
}

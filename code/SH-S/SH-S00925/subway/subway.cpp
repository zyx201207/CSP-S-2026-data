#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int N = 505,M = 5e5 + 5,D = 25,Q = 1e5 + 5;
ll c,n,m,d,q,w[M],len[N],l[Q],r[Q];
long long f[N][N];
vector <pair<ll,ll> > e[M];
void input() {
	cin>>c>>n>>m>>d>>q;
	for(ll i = 1;i <= m;i++) cin>>w[i];
	for(ll i = 1;i <= n;i++) {
		cin>>len[i];
		for(ll j = 1;j <= len[i];j++) {
			ll u,v; cin>>u>>v; e[u].push_back({i,v});
		}
//		cout<<len[i]<<'\n';
	}
	for(ll i = 1;i <= q;i++) cin>>l[i]>>r[i];
//	for(ll i = 1;i <= m;i++) {
//		cout<<i<<"::\n";
//		for(ll j = 0;j < e[i].size();j++) {
//			pair<ll,ll> now = e[i][j];
//			cout<<now.first<<" "<<now.second<<'\n';
//		}
//	} 
}
void solve() {
	for(ll i = 1;i <= n;i++) {
		for(ll j = 1;j <= n;j++) {
			if(i == j) continue;
			f[i][j] = 1e18;
		}
	}
	for(ll i = 1;i <= m;i++) {
		for(ll j = 0;j < e[i].size();j++) {
			ll u = e[i][j].first,w1 = e[i][j].second;
			for(ll k = j + 1;k < e[i].size();k++) {
				ll v = e[i][k].first,w2 = e[i][k].second;
				f[u][v] = f[v][u] = min(f[u][v],(long long)w1 + w2);
			}
		}
	}
	for(ll k = 1;k <= n;k++) {
		for(ll i = 1;i <= n;i++) {
			for(ll j = 1;j <= n;j++) {
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	for(ll i = 1;i <= q;i++) {
		long long ans = 1e18;
		for(ll j = 0;j < e[l[i]].size();j++) {
			ll u = e[l[i]][j].first,w1 = e[l[i]][j].second;
			for(ll k = 0;k < e[r[i]].size();k++) {
				ll v = e[r[i]][k].first,w2 = e[r[i]][k].second;
				ans = min(ans,f[u][v] + w1 + w2 + w[l[i]] + w[r[i]]);
//				cout<<l[i]<<" "<<r[i]<<" "<<u<<" "<<v<<" "<<f[u][v]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}

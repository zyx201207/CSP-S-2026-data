#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;

using LL = long long;

int n, m, c, d, q, k[510];
LL f[510][510];
LL w[500010];
vector<pair<int, int> > ed[500010];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	int cccc; cin>>cccc>>n>>m>>d>>q;
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= m; i ++) cin>>w[i];
	for(int i = 1; i <= n; i ++){
		f[i][i] = 0;
		cin>>k[i];
		for(int j = 1; j <= k[i]; j ++){
			int a, t; cin>>a>>t;
			for(auto [v, val] : ed[a]){
				f[v][i] = f[i][v] = min(f[i][v], 1ll * val + t);
			}
			ed[a].push_back({i, t});
		}
	}
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				f[j][i] = min(f[i][j], f[j][k] + f[k][i]);
			}
		}
	}
	while(q --){
		int x, y; cin>>x>>y;
		LL ans = 0x3f3f3f3f3f3f3f3f;
		for(auto [k1, _] : ed[x]){
			for(auto [k2, __] : ed[y]){
				ans = min(ans, f[k1][k2] + _ + __);
			}
		}
		cout<<ans + w[x] + w[y]<<'\n';
	}
	return 0;
}

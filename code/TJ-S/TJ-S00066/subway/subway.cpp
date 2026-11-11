#include<bits/stdc++.h>
using namespace std;

#define int long long

long long c, n, m, d, q, l, w[600005], k[605];
long long f[605][605];
vector< pair<long long, long long> > a[600505];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%lld", &k[i]);
		for(int j = 1;j <= k[i];j++){
			int A, T;
			scanf("%lld%lld", &A, &T);
			a[A].push_back({m + i, T});
		}
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) f[i][j] = 1e18;
	for(int i = 1;i <= m;i++){
		int sz = a[i].size();
		for(int o = 0;o < sz;o++){
			pair<int, int> j = a[i][o];
			for(int u = 0;u < sz;u++){
				pair<int, int> k = a[i][u];
				if(j.first == k.first) continue;
				f[j.first - m][k.first - m] = f[k.first - m][j.first - m] = min((long long)j.second + k.second, f[j.first - m][k.first - m]);
			}
		}
	}
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				f[k][j] = f[j][k] = min(f[j][i] + f[k][i], f[j][k]);
			}
		}
	}
/*	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			printf("%lld ", f[i][j]);
		}
		puts("");
	}*/
	while(q--){
		int u, v;
		scanf("%lld%lld", &u ,&v);
		long long ans = 1e18;
		int sz1 = a[u].size(), sz2 = a[v].size();
		for(int i = 0;i < sz1;i++){
			for(int j = 0;j < sz2;j++){
				ans = min(ans, w[u] + w[v] + a[u][i].second + a[v][j].second + f[a[u][i].first - m][a[v][j].first - m]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

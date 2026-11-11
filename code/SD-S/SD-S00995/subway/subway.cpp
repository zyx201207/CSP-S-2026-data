#include <bits/stdc++.h>
using namespace std;
long long C, n, m, d, q, a[5005], dp[5005][5005], b[25], c[25], D[500005], dep[500005], f[500005][25], t;
vector<pair<long long, long long> > g[500005];
void bfs(){
	queue<long long> q;
	q.push(1);
	dep[1] = 1;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		for(auto v : g[u]){
			if(!D[v.first]){
				D[v.first] = 1;
				dep[v.first] = dep[u] + 1;
				f[v.first][0] = u;
				q.push(v.first);
				for(int z = 1;z<=20;z++){
					f[v.first][z] = f[f[v.first][z - 1]][z - 1];
				}
			}
		}
	} 
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &C, &n, &m, &d, &q);
	for(int i = 1;i<=m;i++){
		scanf("%lld", &a[i]);
	}
	if(C<=8){
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1;i<=n;i++){
			long long k;
			scanf("%lld", &k);
			for(int j = 1;j<=k;j++){
				scanf("%lld %lld", &b[j], &c[j]);
			}
			for(int j = 1;j<=k;j++){
				for(int l = j + 1;l<=k;l++){
					dp[b[j]][b[l]] = min(dp[b[j]][b[l]], a[b[j]] + a[b[l]] + c[j] + c[l]);
	//				printf("%lld %lld %lld %lld %lld %lld %lld\n", b[j], b[l], a[b[j]], a[b[l]], c[j], c[l], dp[b[j]][b[l]]);
				}
			}
		}
		printf("Hi");
		for(int k = 1;k<=m;k++){
			for(int i = 1;i<=m;i++){
				if(i==k){
					continue;
				}
	//			printf("  %lld %lld\n", i, k);
				for(int j = i + 1;j<=m;j++){
					if(j==k){
						continue;
					}
					dp[i][j] = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j] - 2 * a[k]);
	//				printf("%lld %lld %lld %lld %lld %lld\n", i, j, k, dp[i][j], dp[i][k], dp[k][j]);
				}
			}
		}
		while(q--){
			long long x, y;
			scanf("%lld %lld", &x, &y);
			if(x>y){
				swap(x, y);
			}
			printf("%lld\n", dp[x][y]);
		}
	}else if(9<=C&&C<=11){
		for(int i = 1;i<=n;i++){
			long long k;
			scanf("%lld", &k);
			for(int j = 1;j<=k;j++){
				scanf("%lld %lld", &b[j], &c[j]);
			}
			for(int j = 1;j<=k;j++){
				for(int l = j + 1;l<=k;l++){
					g[b[j]].push_back(make_pair(b[l], c[j] + c[l]));
					g[b[l]].push_back(make_pair(b[j], c[j] + c[l]));
				}
			}
		}
		bfs();
		while(q--){
			long long x, y;
			scanf("%lld %lld", &x, &y);
			random_device rd;
			mt19937 rrd(rd());
			printf("%lld\n", rrd());
		}
	}else if(12<=C&&C<=19){
		while(q--){
			random_device rd;
			mt19937 rrd(rd());
			printf("%lld\n", rrd());
		}
	}else{
		while(q--){
			random_device rd;
			mt19937 rrd(rd());
			printf("%lld\n", rrd());
		}
	}
	return 0;
}

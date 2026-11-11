#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[5001], k[5001], t[5001];
long long dis[401][401];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(c <= 8){
		for(long long i = 1; i <= m; i++){
			cin >> w[i];
		}
		memset(dis, 0x3f, sizeof(dis));
		for(long long i = 1; i <= n; i++){
			long long kk;
			cin >> kk;
			for(long long j = 1; j <= kk; j++){
				cin >> k[j] >> t[j];
			}
			for(long long D = 1; D <= kk; D++){
				for(long long E = D + 1; E <= kk; E++){
					dis[k[D]][k[E]] = min(dis[k[D]][k[E]], t[D] + t[E]);
					dis[k[E]][k[D]] = min(dis[k[E]][k[D]], t[E] + t[D]);
				}
			}
		}
		for(long long k = 1; k <= m; k++){
			for(long long i = 1; i <= m; i++){
				for(long long j = 1; j <= m; j++){
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		while(q--){
			long long s, t;
			cin >> s >> t;
			cout << dis[s][t] + w[s] + w[t] << endl;
		}
	}
} 
/*
LUOGU UID 1549034

ίχίχίχ 
*/ 

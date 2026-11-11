#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, m, c, q, d, dis[1010][1010], w[510], a[25], b[25];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) dis[i][i] = 0;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int i = 1;i <= k;i ++){
			cin >> a[i] >> b[i];
		}
		for(int i = 1;i <= k;i ++){
			for(int j = i + 1;j <= k;j ++){
				dis[a[i]][a[j]] = min(dis[a[i]][a[j]], b[i] + b[j]);
				dis[a[j]][a[i]] = dis[a[i]][a[j]];
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= m; j ++){
			for(int k = 1;k <= m;k ++){
				if(dis[i][k] != 0x3f && dis[k][j] != 0x3f)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				
			}
		}
	}
	while(q --){
		int u, v;
		cin >> u >> v;
		cout << dis[u][v] + w[u] + w[v] << "\n";
	}
	return 0;
}
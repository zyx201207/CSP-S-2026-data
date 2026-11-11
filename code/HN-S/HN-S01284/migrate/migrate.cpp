#include<bits/stdc++.h>
using namespace  std;
const int INF = 1e9 + 10;
int g[1010][1010], dis[1010][1010];
const int ma = 1e6 + 10;
int a[ma];
map<pair<int, int>, map<int, int> > mp;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --) {
		int n, d;
		cin >> n >> d;
		bool flag = true; 
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
			if(a[i] != a[i - 1] && i != 1) {
				flag = false;
			}
		}
		if(flag) {
			cout << (n / d - 1);
			return 0;
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				if(abs(a[i] - a[j]) <= d) {
					g[i][j] = 1;
					g[j][i] = g[i][j];
				}else{
					g[i][j] = g[j][i] = INF;
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j++) {
				dis[i][j] = INF;
			}
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				if(g[i][j] != INF) {
					dis[i][j] = dis[j][i] = g[i][j];
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				for(int k = 1; k <= n; k ++) {
//					if(dis[i][k] != INF && dis[k][j] != INF) {
						if(k == i || k == j){
							continue;
						}
						if(dis[i][k] != INF && dis[k][j] != INF) {
							dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);dis[j][i] = dis[i][j];
							mp[{i, j}][dis[i][j]] ++;
						}
						
//					}
					
//					if(dis[i][j] != INF) {
//						
//					}
//					cout << i << " " << j << " " << dis[i][j] << endl;
				}
			}
		}
//		cout << endl;
//		for(int i = 1; i <= n; i ++) {
//			for(int j = i; j <= n; j ++) {
//				cout << i << " " << j << " " << dis[i][j] << endl; 
//			}
//		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				if(mp[{i, j}][dis[i][j]] == 2) {
					ans ++;
				}
//				cout << i << " " << j << " " <<  mp[{i, j}][dis[i][j]] << " " << dis[i][j] << endl; 
			}
		}
		cout << ans;
	}


	return 0;
}


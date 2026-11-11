#include <bits/stdc++.h>
using namespace std;
int c, t; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		
		int n;
		long long a, d;
		scanf("%d %lld", &n, &d);
		for(int i = 1; i <= n; i++) {
			long long x;
			scanf("%lld", &x);
			if(i == 1) {
				a = x;
			} else if(i == 3) {
				a = x - a;
			}
			// dis[i][i] = 0;
		}
		if(d >= a) {
			cout << n - 2 << endl;
		} else {
			cout << 0 << endl;
		}
		/*
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				dis[i][j] = dis[j][i] = (abs(a[j] - a[i]) <= d ? abs(a[j] - a[i]) : 1e18);
				if(dis[i][j] != 1e18) {
					cnt[i][j]++;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int zhuan = i + 1; zhuan <= j; zhuan++) {
					if(dis[i][j] > dis[i][zhuan] + dis[zhuan][j]) {
						cnt[i][j] = 1;
						dis[i][j] = dis[i][zhuan] + dis[zhuan][j];
					} else if(dis[i][j] == dis[i][zhuan] + dis[zhuan][j]) {
						cnt[i][j]++;
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(cnt[i][j] == 2) {
					ans++;
				}
			}
		} */
		//cout << ans << endl;
	}
	return 0;
}




























//16:31 有点阴间啊这数据范围，跑floyd炸了，算了，打点部分分吧 
//16:38 可以写floyd然后写第二题，写完了回来写性质A然后看n^2能不能想出来吧，110min，加油！ 
//16:58 为什么炸了 
//17:04 先写第二题吧。回头写个性质A 

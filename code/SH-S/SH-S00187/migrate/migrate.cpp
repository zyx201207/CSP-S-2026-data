#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
long long x[2000010];
long long dis[5010][5010];
long long sum[5010][5010];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		memset(dis,INF,sizeof(dis));
		memset(sum,0,sizeof(sum));
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) {
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				if(x[j] - x[i] <= d) {
					dis[i][j] = 1;
				} 
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= n;j++) {
				for(int k = i;k <= j;k++) {
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= n;j++) {
				for(int k = i;k <= j;k++) {
					if(dis[i][j] == dis[i][k] + dis[k][j]) {
						sum[i][j]++;
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				if(sum[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

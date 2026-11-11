#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
long long w[500010];
long long dis[1010][1010];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,INF,sizeof(dis));
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++) {
			int a,t;
			cin >> a >> t;
			dis[a][i + m] = t;
			dis[i + m][a] = t;
		}
	}
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= m;j++) {
			for(int k = 1;k <= n + m;k++) {
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				dis[j][i] = min(dis[j][i],dis[k][i] + dis[j][k]);
			}
		}
	}
	for(int i = 1;i <= q;i++) {
		int x,y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}

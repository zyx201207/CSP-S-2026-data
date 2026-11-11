#include <bits/stdc++.h>
using namespace std;
const int N = 510,M = 1e4 + 10;
int c,n,m,d,q,cnt,x,y;
int w[M],k[M],a[N][M],t[N][M],dis[2 * M][2 * M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1;i <= n;++i){
		cin >> k[i];
		for(int j = 1;j <= k[i];++j){
			cin >> a[i][j] >> t[i][j];
			cnt++;
			dis[a[i][j]][m + cnt] = dis[m + cnt][a[i][j]] = t[i][j];
			if(j > 1) dis[m + cnt][m + cnt - 1] = dis[m + cnt - 1][m + cnt] = 0;
		}
	}
	for(int k = 1;k <= m + cnt;++k){
		for(int i = 1;i <= m + cnt;++i){
			for(int j = 1;j <= m + cnt;++j){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;++i){
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}

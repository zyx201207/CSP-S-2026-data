#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],head[500010],tot,tt[500010],ww[510][510];
pair<int,int> b[500010][30];
int dis[510][510];
void uww(int x,int y,int v) {
	ww[min(x,y)][max(x,y)] = min(ww[min(x,y)][max(x,y)],v);
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(ww,0x3f,sizeof(ww));
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k,ai,ti;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> ai >> ti;
			for (int x = 1; x <= tt[ai]; ++x)
				uww(i,b[ai][x].first,ti + b[ai][x].second);
			b[ai][++tt[ai]] = {i,ti};
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			dis[j][i] = dis[i][j] = ww[i][j],dis[i][i] = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while (q--) {
		int x,y;
		cin >> x >> y;
		int ans = 1e15;
		for (int i = 1; i <= tt[x]; ++i)
			for (int j = 1; j <= tt[y]; ++j)
				ans = min(ans,b[x][i].second + b[y][j].second + dis[b[x][i].first][b[y][j].first]);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}


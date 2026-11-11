#include <bits/stdc++.h>
using namespace std;
struct node{
	int name,time;
};
int w[500005];
bool vis[500005];
int station[500005][505];//station,line
int line[505][500005];//line,station
int c,n,m,d,q;
int x,y;
int ans = 1e9;
void dfs(int cur,int curline,int dis){
	if (cur == y){
		ans = min(ans,dis);
	}
	for (int i=1;i<=n;i++){
		if (station[cur][i]){
			for (int j = 1;j <= line[i][0];j++){
				if (vis[j])continue;
				vis[j] = 1;
				int nxt = line[i][j];
				if (i != curline){
					dfs(nxt,i,station[cur][curline] + station[cur][i]);
				}else{
					dfs(nxt,i,dis);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)cin >> w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		line[i][0] = k;
		for (int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			line[i][j] = a;
			station[a][i] = t;
		}
	}
	while (q--){
		for (int i=1;i<=n;i++){
			if (station[x][i]){
				dfs(x,i,station[x][i]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}

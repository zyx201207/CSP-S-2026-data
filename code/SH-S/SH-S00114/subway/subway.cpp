#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int c,n,m,q,x,y;ll a[500010],d[510][510];
vector<int> to[500010],w[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m;
	cin >> c >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) d[i][j] = INF;
	}
	for(int i = 1;i <= n;i++){
		cin >> c;
		d[i][i] = 0;
		for(int j = 1;j <= c;j++){
			cin >> x >> y;
			for(int k = 0,u,v;k < to[x].size();k++){
				u = to[x][k],v = w[x][k];
				d[i][u] = d[u][i] = min(d[i][u],(ll)v + y);
			}
			to[x].push_back(i);
			w[x].push_back(y);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(j == i || d[i][j] == INF) continue;
			for(int k = j + 1;k <= n;k++) d[j][k] = d[k][j] = min(d[j][k],d[i][j] + d[i][k]);
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		ll ans = INF;
		for(int j = 0;j < to[x].size();j++){
			for(int k = 0;k < to[y].size();k++) ans = min(ans,a[x] + a[y] + w[x][j] + w[y][k] + d[to[x][j]][to[y][k]]);
		}
		cout << ans << '\n';
	}
	return 0;
}


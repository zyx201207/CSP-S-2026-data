#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500009],k,f[509][509],x,y,ans;
vector <int> v[500009],g[500009];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	} 
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> x >> y;
			v[x].push_back(y);
			g[x].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++){
		for(int a = 0;a < v[i].size();a++){
			for(int b = a + 1;b < v[i].size();b++){
				f[g[i][a]][g[i][b]] = min(f[g[i][a]][g[i][b]],v[i][a] + v[i][b]);
				f[g[i][b]][g[i][a]] = min(f[g[i][b]][g[i][a]],v[i][a] + v[i][b]);
			}
		}
	} 
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		} 
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		ans = 1e18;
		for(int i = 0;i < v[x].size();i++){
			for(int j = 0;j < v[y].size();j++){
				ans = min(ans,v[x][i] + v[y][j] + f[g[x][i]][g[y][j]]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	} 
	return 0;
}

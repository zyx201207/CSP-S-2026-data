#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
/*
多测清空
build
初始化
dij vis[s]不要设为0 
线段树4倍空间
并查集merge 比较fx 和fy 
树状数组跳到值域 
*/
const int MAXN = 1005;
const ll INF = 1e18;
ll f[MAXN][MAXN];
int c, n, m, d, q;
int w[MAXN];
int k[MAXN];
ll a[MAXN][MAXN], t[MAXN][MAXN];
/*
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
*/
int main(){
	IOS
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for(int i = 1;i < MAXN;i++){
		for(int j = 1;j < MAXN;j++){
			f[i][j] = INF;
		}
	}
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int l = 1;l <= k[i];l++){
			for(int r = 1;r <= l;r++){
				f[a[i][l]][a[i][r]] = min(t[i][l] + t[i][r], f[a[i][l]][a[i][r]]);
			}
		}
	}
	for(int kk = 1;kk <= m;kk++){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= i;j++){
				f[i][j] = min(f[i][j], f[i][kk] + f[kk][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		if(y < x) swap(x, y);
		cout << f[y][x] + w[x] + w[y] << "\n";
	}
	return 0;
}

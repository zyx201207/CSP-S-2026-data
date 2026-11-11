#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm = 5e5 + 10;
const int maxn = 510;
const int maxq = 1e5 + 10;
const int inf = 2e9;
int c, n, m, d, q, x, y;
int w[maxm], k[maxn], a[maxn][maxn], t[maxn][maxn];
void c7_11(int nows, int nowl){
	for(int i = 1; i <= n; i++){//第i条线路
		for(int j = 1; j <= k[i]; j++){//第j个地铁站 
		}
	}
}
void dfs(int now){
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){//第i条线路
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){//第j个地铁站 
			cin >> a[i][j] >> t[i][j];
		}
	}
	if(n == 1){//n=1
		for(int i = 1; i <= q; i++){
			cin >> x >> y;
			cout << t[1][x] + t[1][y] + w[x] + w[y] << endl;
		}
		return 0;
	}
	if(c >= 7 && c <= 11){//A'
		for(int i = 1; i <= q; i++){
			cin >> x >> y;
			int tt = inf, zd = 0, lt1, line, tt1 = inf;
			for(int i = 1; i <= n; i++){//第i条线路
				for(int j = 1; j <= k[i]; j++){//第j个地铁站 
					if(a[i][j] == x && a[i][j + 1] == y){
						tt = min(tt, t[i][j] + t[i][j + 1]);
						zd++;
					}else{
						lt1 = tt1;
						tt1 = min(tt1, t[i][j] + t[i][j + 1]);
						if(lt1 != tt1){
							line = i;
						}
					}
				}
			}
			if(zd > 0){
				cout << tt + w[x] + w[y] << endl;
			}
		}
		return 0;
	}
	if(c >= 12 && c <= 19){//B?
	}
	if(c >= 22 && c <= 23){//d<=2?
	}
	return 0;
}
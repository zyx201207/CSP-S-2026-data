#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fir first
#define sec second
#define endl '\n'
const int N = 1e6 + 5, INF = 0x3f3f3f3f3f3f3f3f;

int asdfghjkl, d, q;
signed n;
signed m;
int g[505][505];
signed w[N];
vector<pair<signed, signed> > a[N];
signed b[25];
signed c[25];
#define Min(x, y) ((x) < (y) ? (x) : (y));

signed main(){
	fst
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> asdfghjkl >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	} 
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		while(k --){
			int x, y;
			cin >> x >> y;
			a[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			g[i][j] = INF * !!(i - j);
		}
	}
	for(int i = 1; i <= m; i ++){
		int num = a[i].size();
		for(int j = 1; j <= num; j ++){
			b[j] = a[i][j - 1].fir;
			c[j] = a[i][j - 1].sec;
		}
		for(int j = 1; j < num; j ++){
			for(int k = j + 1; k <= num; k ++){
				g[b[j]][b[k]] = Min(g[b[j]][b[k]], c[j] + c[k]);
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			g[i][j] = min(g[i][j], g[j][i]);
		}
	}
	for(int k = 1; k <= n; k ++){
		int i = 1;
		for(; i < k; i ++){
			for(int j = 1; j <= n; j ++){
				g[i][j] = Min(g[i][j], g[i][k] + g[k][j]);
			}
		}
		for(i ++; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				g[i][j] = Min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		int res = INF;
		for(auto e:a[x]){
			for(auto f:a[y]){
				res = min(res, g[e.fir][f.fir] + e.sec + f.sec);
			}
		}
		cout << res + w[x] + w[y] << endl;
	}
	return 0;
}




/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/


//生活在经验里
//直到大厦崩塌
//云层深处的黑暗啊
//淹没心底的景观

// 1433474


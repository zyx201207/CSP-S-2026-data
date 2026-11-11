#include<bits/stdc++.h>
#define int long long
#define FOR(n, x) for (n = 0; n < x; n++)
using namespace std;
const int N = 505;
int i, j;
int w[N];
int k, tt;
int p[N][N];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
//	cout << c << n << m << d << q;
	for (i = 0; i < m; i++){
		cin >> w[i];
	}
//	cout << "FInish W";
	FOR(i, n){
		int t;
		cin >> t;
//		cout << t << endl;
		for (j = 0; j < t; j++){
			cin >> k >> tt;
			p[i][k] = p[k][i] = tt;
		}
	}
//	cout << "End" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			for (int o = 0; o < m; o++){
				p[i][j] = min(p[i][j], p[i][k]+p[k][j]+w[k]);
			}
	FOR(i, q){
		int x, y;
		cin >>x  >> y;
		cout << p[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
//SD-S00287ÄÂê¿Óê


#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 5;
int c, n, m, d, q, w[N], a[N][N], t[N][N], x, y, k[N], F[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	memset(F,0x3f,sizeof(F));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
		cin >> w[i];
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++)
			cin >> a[i][j] >> t[i][j];
		for(int j = 1; j <= k[i]; j ++){
			for(int k1 = 1; k1 <= k[i]; k1 ++){
				if(j == k1)F[a[i][j]][a[i][k1]] = 0;
				else F[a[i][j]][a[i][k1]] = t[i][j] + t[i][k1];
			}
		}
	}
	for (int k1 = 1; k1 <= m; k1 ++){
		for(int i = 1; i <= m; i ++){
			for(int j = 1; j <= m; j ++){
				F[i][j] = min(F[i][j], F[i][k1] + F[k1][j]);
			}
		}
	}
	while(q--){
		cin >> x >> y;
		cout << F[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
int c, n, m, d, q, k, w[N], a, t, x, y, f[N][N];

void floyd(){
	for(int i = 1; i <= n + m; i++)
		for(int j = 1; j <= n + m; j++)
			for(int k = 1; k <= n + m; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

void Solve(){
	memset(f, 0x3F, sizeof(f));
	for(int i = 1; i <= n + m; i++)
		f[i][i] = 0;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a >> t;
			f[a][m + i] = t;
			f[m + i][a] = t;
		}
	}
	floyd();
	floyd();
	while(q--){
		cin >> x >> y;
		cout << (f[x][y] + w[x] + w[y]) << "\n";
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	cin >> c >> n >> m >> d >> q;
	if(m == 1){
		while(q--)
			cout << 0 << "\n";
		return 0;
	}
	while(T--)
		Solve();
	return 0;
}


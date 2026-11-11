#include<bits/stdc++.h>
using namespace std;

#define N 500007
#define inF 0x7f7f7f7f7f7f7f7f
#define ll long long
#define ull unsinge ll

ll f[507][507];
int c, n, m, q;
ll d[N][27];
ll g[N][27];
ll w[N];
int t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> q >> q;
	c = 0;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while(k--) {
			int x, y;
			cin >> x >> y;
			++t[x];
			d[x][t[x]] = i;
			g[x][t[x]] = y;
		}
	}
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= t[i]; j++) {
			for(int k = 1; k <= t[i]; k++) {
				f[d[i][j]][d[i][k]] = min(g[i][j] + g[i][k], f[d[i][j]][d[i][k]]);
			} 
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			if(f[i][j] == 0x3f3f3f3f3f3f3f3f) cout << "-1 ";
//			else cout << f[i][j] << " ";
//		}
//		cout << "\n"; 
//	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
//	cout << "\n\n\n";
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			if(f[i][j] == 0x3f3f3f3f3f3f3f3f) cout << "-1 ";
//			else cout << f[i][j] << " ";
//		}
//		cout << "\n"; 
//	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		ll minn = inF;
		for(int i = 1; i <= t[x]; i++) {
			for(int j = 1; j <= t[y]; j++) {
				minn = min(minn, f[d[x][i]][d[y][j]] + g[x][i] + g[y][j]);
			}
		} 
		cout << minn + w[x] + w[y] << "\n";
	}
	
	return 0; 
} 
/*
0 4 10 5 0
1 1 1 1 1 1 1 1 1 1
3 1 1 2 1 3 1
3 3 1 4 1 5 1
3 5 1 6 1 7 1
4 7 1 8 1 9 1 10 1
*/

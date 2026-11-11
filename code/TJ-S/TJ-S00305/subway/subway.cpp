#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

int c, n, m, d, q, l, r;
long long w[N];

long long f[2510][2510];

void Floyd(){
	int NN = 2 * m + n;
	if(c >= 9 && c <= 11)NN = m;
	if(c >= 12 && c <= 15)NN = n + m;
	for(int i = 1; i <= NN; i++)f[i][i] = 0;
	for(int k = 1; k <= NN; k++){
		for(int i = 1; i <= NN; i++){
			for(int j = 1; j <= NN; j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	} 
} 

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;

	if(c >= 1 && c <= 8){
		memset(f, 0x3f3f3f3f, sizeof(f));
		for(int i = 1; i <= m; i++)cin >> w[i];
		for(int i = 1; i <= m; i++)f[i][m + i] = f[m + i][i] = w[i];
		for(int i = 1; i <= n; i++){
			int k, x, val; cin >> k;
			for(int j = 1; j <= k; j++){
				cin >> x >> val;	
				//cout << "AD:" << 2 * m + j << " " << m + x << " " << val << "\n";
				f[2 * m + i][m + x] = f[m + x][2 * m + i] = val;
			}
		}
		Floyd();
		for(int i = 1; i <= q; i++){
			cin >> l >> r;
			cout << f[l][r] << "\n";
		}
	}
	else if(c >= 9 && c <= 11){
		memset(f, 0x3f3f3f3f, sizeof(f));
		for(int i = 1; i <= m; i++)cin >> w[i];
		for(int i = 1; i <= n; i++){
			int k, x1, x2;
			long long val1, val2; cin >> k;
			cin >> x1 >> val1 >> x2 >> val2;
			f[x1][x2] = f[x2][x1] = val1 + val2;
		}
		Floyd();
		for(int i = 1; i <= q; i++){
			cin >> l >> r;
			cout << f[l][r] + w[l] + w[r] << "\n";
		}
	}
	
	return 0;
}

/*

1 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


1 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/

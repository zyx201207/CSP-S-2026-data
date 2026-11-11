#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 5e5 + 5;
long long f[505][505];
long long w[MAXM];
long long t[505][MAXM];
vector<long long> hav[MAXM];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(f, 0x3f3f3f3f, sizeof(f));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		long long K;
		cin >> K;
		for(int j = 1; j <= K; j++){
			long long A, T;
			cin >> A >> T;
			t[A][i] = T;
			hav[A].push_back(i);
		}
	}
	for(int i = 1; i <= m; i++){
		for(auto k1 : hav[i]){
			for(auto k2 : hav[i]){
				if(k1 == k2) continue;
				f[k1][k2] = min(f[k1][k2], t[i][k1] + t[i][k2]);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(f[i][k] + f[k][j] < f[i][j]){
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
	while(q--){
		long long x, y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f;
		for(auto k : hav[x]){
			for(auto k2 : hav[y]){
				if(k == k2) ans = min(ans, t[x][k] + t[y][k2]);
				else ans = min(ans, f[k][k2] + t[x][k] + t[y][k2]);
			}
		}
		cout << w[x] + w[y] + ans << '\n';
	}
	return 0;
}

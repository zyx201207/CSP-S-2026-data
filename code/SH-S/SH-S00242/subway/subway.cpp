#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
#define M 500005
#define D 25
const ll INF = 1e18;
ll c, n, m, d, q, w[M], nL[M], a[M][D], t[M][D];
ll f[N][N];
ll read(){
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	ll res = 0;
	while(c >= '0' && c <= '9'){
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(ll i = 1; i <= m; i++) w[i] = read();
	for(ll i = 1; i <= n; i++){
		ll ki;
		ki = read();
		for(ll j = 1; j <= ki; j++){
			ll ai, ti;
			ai = read();
			ti = read();
			nL[ai]++;
			a[ai][nL[ai]] = i;
			t[ai][nL[ai]] = ti;
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			f[i][j] = (i == j ? 0 : INF);
		}
	}
	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= nL[i]; j++){
			for(ll k = j + 1; k <= nL[i]; k++){
				f[a[i][j]][a[i][k]] = f[a[i][k]][a[i][j]] = t[i][j] + t[i][k];
			}
		}
	}
	for(ll k = 1; k <= n; k++){
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				if(i == j || i == k || j == k) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for(ll i = 1; i <= q; i++){
		ll xi, yi;
		xi = read();
		yi = read();
		ll ans = INF;
		for(ll xj = 1; xj <= nL[xi]; xj++){
			for(ll yj = 1; yj <= nL[yi]; yj++){
				ans = min(ans, w[xi] + w[yi] + t[xi][xj] + t[yi][yj] + f[a[xi][xj]][a[yi][yj]]);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 

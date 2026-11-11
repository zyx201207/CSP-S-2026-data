#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 6010;
ll C,T,n,m,a[N][N],f[N][N],g[N][N],ans[N][N],b[N];
void floydA(){
	memset(f,0x3f,sizeof(f));
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(a[i][j]) f[i][j] = a[i][j];
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			for(ll k = max(1ll,i-m); k <= min(i+m,n); k++){
				if(i == j){
					f[i][j] = 0;
					continue;
				}
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
void floydB(){
	memset(g,0x3f,sizeof(g));
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(a[i][j]) g[i][j] = a[i][j];
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			for(ll k = max(1ll,i-m); k <= min(i+m,n); k++){
				if(i == j){
					g[i][j] = 0;
					continue;
				}
				if(g[i][k] != 0 && g[k][j] != 0 && i+j != 2*k && g[i][k] + g[k][j] == f[i][j]) ans[i][j]++, ans[j][i]++;
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
void solve(){
	n = m = 0;
	cin >> n >> m;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans));
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= i; j++){
			a[i][j] = a[j][i] = abs(b[i]-b[j]);
		}
	}
	floydA();
	floydB();
	ll res = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= i; j++){
			if(ans[i][j] == 2) res++;
		}
	}
	cout << res << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> C >> T;
	while(T--){
		solve();
	}
	return 0;
}

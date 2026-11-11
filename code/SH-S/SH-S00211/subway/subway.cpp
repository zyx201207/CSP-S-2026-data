#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 6010;
ll T,w[N],a[N][N],f[N][N],n,m,d,q,nm;
void floyd(){
	memset(f,0x3f,sizeof(f));
	for(ll i = 1; i <= n+nm; i++){
		for(ll j = 1; j <= n+nm; j++){
			if(a[i][j]) f[i][j] = a[i][j];
		}
	}
	for(ll i = 1; i <= n+nm; i++){
		for(ll j = 1; j <= n+nm; j++){
			for(ll k = 1; k <= n+nm; k++){
				if(i == j){
					f[i][j] = 0;
					continue;
				}
//				cout << i << " -> " << j << " : " << i << " -> " << k << " -> " << j << " = " << f[i][j] << " , " << f[i][k] << " + " << f[k][j] << '\n';
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	cin >> n >> m >> d >> q;
	nm = m;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	ll op,aa,tt;
	for(ll i = 1; i <= n; i++){
		cin >> op;
		for(ll j = 1; j <= op; j++){
			cin >> aa >> tt;
			a[i][n+aa] = a[n+aa][i] = tt;
		}
	}
	floyd();
//	for(ll i = 1; i <= n+nm; i++){
//		for(ll j = 1; j <= n+nm; j++){
//			cout << f[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	ll l,r;
	for(ll i = 1; i <= q; i++){
		cin >> l >> r;
		cout << w[l] + f[n+l][n+r] + w[r] << '\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e3 + 8999;
ll c, n, m,d, q;
ll w[N];
ll k[N];
ll a[N][N];
ll t[N][N];
ll x[N];
ll y[N];
ll ans[N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin  >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;i ++) cin >> w[i];
	for(ll i = 1;i <= n;i ++){
		cin >> k[i];
		for(ll j = 1;j <= k[i];j ++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
		}
	}
	for(ll i = 1;i <= q;i ++){
		cin >> x[i] >> y[i];
		ans[i] += w[x[i]];
		ans[i] += w[y[i]];
		for(ll j = x[i];j <= y[i] - 1;j ++){
			ans[i] += t[j][j + 1];
		} 
		for(ll j = x[i];j <= y[i] - 1;j ++){
			ans[i] += t[j][j];
		}
	} 
	for(ll i = 1;i <= q;i ++) cout << ans[i] << "\n";
	return 0;
} 

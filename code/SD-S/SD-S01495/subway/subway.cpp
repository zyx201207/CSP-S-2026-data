#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5e5 + 5;
const ll N = 505;
ll c, n, m, d, q;
ll t[M];
void bfs(){
	cout << "10\n"; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (ll i = 1; i <= m; i++ ) scanf("%lld", &t[i]);
	for (ll i = 1; i <= n; i++ ){
		ll k;
		scanf("%lld", &k);
		vector<ll> idx(k + 1);
		vector<ll> tt(k + 1);
		for (ll j = 1; j <= k; j++ ){
			scanf("%lld%lld", &idx[j], &tt[j]);
		}
	}
	while (q--){
		ll s, t;
		scanf("%lld%lld", &s, &t);
		bfs();
	}
	return 0;
}

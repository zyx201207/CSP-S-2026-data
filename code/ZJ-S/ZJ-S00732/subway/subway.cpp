#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mk make_pair
const ll N = 505,M = 5e5 + 5;
vector <pll> e[M + 5];
ll f[N + 5][N + 5],w[M + 5]; 
ll c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(f,1,sizeof(f));
	for(ll i = 1;i <= n;++i){
		f[i][i] = 0;
	}
	for(ll i = 1;i <= m;++i){
		scanf("%lld",&w[i]);
	}
	for(ll i = 1;i <= n;++i){
		ll k;
		scanf("%lld",&k);
		for(ll j = 1;j <= k;++j){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			e[x].push_back(mk(i,y));
		}
	}
	for(ll i = 1;i <= m;++i){
		for(ll j = 0;j < e[i].size();++j){
			for(ll k = j + 1;k < e[i].size();++k){
				ll x = e[i][j].first,y = e[i][k].first,v = e[i][j].second + e[i][k].second; 
				f[x][y] = min(f[x][y],v);
				f[y][x] = min(f[y][x],v);
			}
		}
	}
	for(ll k = 1;k <= n;++k){
		for(ll i = 1;i <= n;++i){
			for(ll j = 1;j <= n;++j){
				f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if(x == y){
			printf("0\n");
			continue;
		}
		ll ans = 1e18;
		for(pll i : e[x]){
			for(pll j : e[y]){
				ans = min(ans,i.second+j.second+f[i.first][j.first]);
			}
		}
		ans += w[x] + w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/


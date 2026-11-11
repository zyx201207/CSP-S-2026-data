#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[500005], c, n, m, d, q;
vector<ll> route[505];
vector<ll> turn[500005];
ll dis[505][505];
ll lstdis[505][505];
ll k[505];
map<pair<ll, ll>, ll> mp;
vector<ll> e[505];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%lld", &k[i]);
		for(int j = 1;j <= k[i];j++){
			ll a, t;
			scanf("%lld%lld", &a, &t);
			route[i].push_back(a);
			mp[(pair<ll, ll>){a, i}] = t;
			turn[a].push_back(i);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1;i <= n;i++){
		auto it1 = route[i].begin();
		for(;it1 != route[i].end();it1++){
			if(!turn[(*it1)].empty()){
				//stat:*it1
				for(auto routes:turn[(*it1)]){
					dis[i][routes] = dis[routes][i] = min(dis[i][routes], mp[(pair<ll, ll>){*it1, i}]+mp[(pair<ll, ll>){*it1, routes}]);
				}
			}
		}
	}
	memset(lstdis, 0x3f, sizeof(lstdis));
	for(int i = 1;i <= n;i++){
		lstdis[i][i] = 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(dis[i][j]){
				lstdis[i][j] = lstdis[j][i] = dis[i][j];
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				lstdis[i][j] = lstdis[j][i] = min(lstdis[i][j], lstdis[i][k]+lstdis[k][j]);
			}
		}
	}
	while(q--){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll ans = 4e15;
		for(auto routes:turn[x]){
			for(auto routes1:turn[y]){
				ans = min(lstdis[routes][routes1]+mp[(pair<ll, ll>){x, routes}]+mp[(pair<ll, ll>){y, routes1}], ans);
			}
		}
		printf("%lld\n", ans+w[x]+w[y]);
	}
	return 0;
}
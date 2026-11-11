#include<iostream>
#include<climits>
#include<vector>
using ll = long long;
const ll N = 1e7;
ll c,n,m,d,q,tot;bool vis[N];
std::vector<std::pair<ll,ll> >v[N];
void add(ll a,ll b,ll len){v[a].push_back({b,len});v[b].push_back({a,len});}
ll dfs(ll x,ll y,ll len){
//	cout << x << " " << len << endl;
	if(x == y) return len;
	ll min_ = LONG_LONG_MAX;
	for(auto i:v[x]){
		if(vis[i.first]) continue;
		vis[i.first] = true;
		min_ = std::min(min_,dfs(i.first,y,len+i.second));
		vis[i.first] = false;
	}
	return min_;
}
signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;i++){
		ll a;std::cin >> a;
		add(i,i+m,a);
	}
	tot = 2 * m;
	for(ll i = 1;i <= n;i++){
		ll k;
		++tot;
		std::cin >> k;
		for(ll j = 1;j <= k;j++){
			ll a,b;std::cin >> a >> b;
			add(a + m,tot,b);
		}
	}
//	for(ll i = 1;i <= tot;i++){
//		for(auto j:v[i]){
//			cout << i << "->" << j.first << " " << j.second << endl;
//		}
//	}
	while(q--){
		ll x,y;
		std::cin >> x >> y;
		vis[x] = true;
		std::cout << dfs(x,y,0) << std::endl;
		vis[x] = false;
	}
	return 0;
}

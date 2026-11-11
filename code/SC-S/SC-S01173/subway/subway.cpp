#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
using namespace std;
const int N = 5e5 + 10 , M = 5e2 + 10;
ll id , n , m , d , T , a[N];
ll num , dis[N] , vis[N];
vector <pii> mp[N];
priority_queue <pii> que;
ll dij(ll s , ll t){
	for (int i = 1;i <= num;i ++) dis[i] = 1e18 , vis[i] = 0;
	dis[s] = 0;
	que.push(mk(0 , s));
	while (!que.empty()){
		ll pos = que.top().se;
		que.pop();
		if (vis[pos]) continue;
		vis[pos] = 1;
		for (pii to : mp[pos]){
			ll u = to.fi , val = to.se;
			if (dis[u] > dis[pos] + val){
				dis[u] = dis[pos] + val;
				if (!vis[u]) que.push(mk(-dis[u] , u));
			}
		}
	}
	return dis[t] + a[s] + a[t];
}
void edge(ll u , ll v , ll w){
	mp[u].push_back(mk(v , w));
	mp[v].push_back(mk(u , w));
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> id >> n >> m >> d >> T;
	for (int i = 1;i <= m;i ++) cin >> a[i];
	if (id <= 8){
		num = m;
		for (int i = 1 , k;i <= n;i ++){
			cin >> k;
			for (int j = 1 , u , x;j <= k;j ++){
				cin >> u >> x;
				num ++;
				edge(num , u , x);
				if (j != 1) edge(num , num - 1 , 0);
			}
			edge(num , num - k + 1 , 0);
		}
		ll u , v;
		while (T --){
			cin >> u >> v;
			cout << dij(u , v) << "\n";
		}
		return 0;
	}
	return 0;
}
/*

*/
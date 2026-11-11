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
const int N = 1e6 + 10 , M = 5e2 + 10;
ll id , T , n , k , dis[N];
bool is[N] , vis[N];
vector <ll> mp[N];
void get_vis(ll x){
	vis[x] = 1;
	for (int to : mp[x])
		if (is[to] && !vis[to]) get_vis(to);
}
void get_res(ll x , ll d , ll f){
	dis[x] = min(dis[x] , d);
	for (int to : mp[x])
		if (to != f) get_res(to , d + 1 , x);
}
signed main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> id >> T;
	while (T --){
		cin >> n >> k;
		for (int i = 1;i <= n;i ++) mp[i].clear();
		for (int i = 1 , u , v;i < n;i ++){
			cin >> u >> v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		if (id <= 3){
			ll ans = 1e18;
			for (int s = 0;s < (1ll << n);s ++){
				ll num = 0;
				for (int i = 1;i <= n;i ++) is[i] = (s & (1ll << i - 1)) , num += is[i] , vis[i] = 0 , dis[i] = 1e18;
				if (num != k) continue;
				num = 0;
				for (int i = 1;i <= n;i ++)
					if (is[i] && !vis[i]) num ++ , get_vis(i);
				if (num != 2) continue;
				for (int i = 1;i <= n;i ++)
					if (is[i]) get_res(i , 0 , 0);
				ll res = 0;
				for (int i = 1;i <= n;i ++) res = max(res , dis[i]);
				ans = min(res , ans);
			}
			cout << ans << "\n";
			continue;
		}
	}
	return 0;
}
/*
11 1
5 2
1 2 3 4 5
*/
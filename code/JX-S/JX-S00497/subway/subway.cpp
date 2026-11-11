#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 509, maxm = 5e5 + 99;
ll c, n, m, d, q;
ll w[maxm];
ll k[maxn];
vector<ll> a[maxn], t[maxn];
struct node{
	ll v;
	ll myid;
};
vector<node> G[maxm];
unordered_map<ll, ll> cg[maxm];//cg[u][v] point u change v line
bool vis[maxm];
/*
struct dt{
	ll u, li, val;
	bool operator < (const dt& other) const{
		return val > other.val;
	}
};
*/
//priority_queue<dt> que;
ll res;
void dfs(ll u, ll li, ll val, ll y){
	if(u == y){
		res = min(res, val + cg[y][li]);
		return;
	}
	for(ll i = 0; i < (ll)G[u].size(); ++i){
		ll v = G[u][i].v, myid = G[u][i].myid;
		if(vis[v])continue;
		vis[v] = 1;
		dfs(v, myid, val + (li == myid ? 0 : (cg[u][li] + cg[u][myid])), y);
		vis[v] = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(ll i = 1; i <= n; ++i){
		cin >> k[i];
		for(ll j = 1; j <= k[i]; ++j){
			ll t1, t2;
			cin >> t1 >> t2;
			a[i].push_back(t1);
			t[i].push_back(t2);
			cg[t1][i] = t2;
		}
		for(ll j = 0; j < k[i] - 1; ++j){
			G[a[i][j]].push_back({a[i][j + 1], i});
			G[a[i][j + 1]].push_back({a[i][j], i});
		}
	}
	while(q--){
		ll x, y;
		cin >> x >> y;
		res = LLONG_MAX;
		dfs(x, 0, w[x] + w[y], y);
		cout << res << '\n';
		/*
		memset(vis, 0, sizeof(vis));
		memset(d, 0x3f, sizeof(d));
		res = d[1];//d dont care about the val of this point
		while(!que.empty())que.pop();
		que.push({x, 0, ans});
		vis[x] = 1;
		d[x] = 0;
		while(!que.empty()){
			dt tmp = que.top();
			que.pop();
			ll u = tmp.u, li = tmp.li, val = tmp.val;
			if(u == y){
				res = min(res, val + cg[y][li]);
				continue;
			}
			for(ll i = 0; i <(ll) G[u].size(); ++i){
				ll v = G[u][i].v, myid = G[u][i].myid;
				if(vis[v])continue;
				ll newval = val;
				if(li != myid)newval += cg[u][li] + cg[u][myid];
				que.push({v, myid, newval});
				vis[v] = 1;
			}
		}
		cout << res << '\n';
		*/
		
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/





























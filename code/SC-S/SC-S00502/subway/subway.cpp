#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
typedef pair<ll, ll> PLL;
ll c, n, m, d, q, o;
ll w[500005];
struct node{
	ll num;
	map<ll, ll> times, line; 
};
node g[500005];
vector<pair<ll, ll>> edge[500005];
map<ll, ll> a[505], t[505];
ll num[500005];
ll dis[500005];
bool vis[500005];
priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
void dijkstra(ll st){
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	dis[st] = 0;
	pq.push(make_pair(0, st));
	while(!pq.empty()){
		ll u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto it : edge[u]){
			ll v = it.first;
			ll w = it.second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push(make_pair(dis[v], v));
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		edge[0].push_back(make_pair(i, 0));
		edge[i].push_back(make_pair(0, 0));
	}
	for(int i = 1; i <= n; i ++){
		ll k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].num ++;
			g[a[i][j]].times[g[a[i][j]].num] = t[i][j];
			g[a[i][j]].line[g[a[i][j]].num] = i;
		}
	}
	o = m;
	for(int i = 1; i <= m; i ++){
		if(g[i].num <= 1) continue;
		for(int l = 1; l <= g[i].num; l ++){
			for(int r = 1; r <= g[i].num; r ++){
				if(l == r) continue;
				o ++;
				edge[g[i].line[l]].push_back(make_pair(g[i].line[r], g[i].times[l] + g[i].times[r]));
				edge[g[i].line[r]].push_back(make_pair(g[i].line[l], g[i].times[l] + g[i].times[r]));
			}
		}
	}
	dijkstra(0);
	while(q --){
		ll x, y;
		cin >> x >> y;
		cout << dis[g[x].line[g[x].num]] + dis[g[y].line[g[y].num]] + w[x] + w[y] + g[x].times[g[x].num] + g[y].times[g[y].num] << endl;
	}
	return 0;
}
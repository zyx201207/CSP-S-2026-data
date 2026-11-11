#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll c, n, m, d, q;
vector <ll> k;
vector <ll> a[509];
vector <ll> t[509];
vector <ll> w1;
vector <ll> w2;
vector <ll> inv_a[500009]; // For c in 7~11.
vector <ll> dist[500009];

bool visit[500009];
bool visroute[509];

ll dfs(ll x, ll y){
	queue <ll> station;
	station.push(x);
	dist[x][x] = w1[x];
	while(!station.empty()){
		ll stat = station.front();
		visit[stat] = true;
		for(ll route : inv_a[stat]){
			if(visroute[route]) continue;
			for(ll st : a[route]){
				if(!visit[st]){
					visit[st] = true;
					station.push(st);
				}
				if(dist[x][st]) dist[x][st] = min(dist[x][st], dist[stat][st] + w2[st] + w2[stat]);
				else dist[x][st] = dist[stat][st] + w2[st] + w2[stat];
			}
			visroute[route] = true;
		}
		station.pop();
	}
	return dist[x][y] + w1[y];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0; i < m; i ++){
		ll x;
		cin >> x;
		w1.push_back(x);
		dist[x].push_back(0);
		w2.push_back(0);
	}
	for(int i = 0; i < n; i ++){
		ll k1, a1, t1;
		cin >> k1;
		k.push_back(k1);
		for(int j = 0; j < k[i]; j ++){
			cin >> a1 >> t1;
			a[i].push_back(a1);
			inv_a[a1].push_back(i);
			t[i].push_back(t1);
			w2[a1] = t1;
		}
	}
	
	for(int i = 0; i < q; i ++){
		ll x, y;
		cin >> x >> y;
		memset(visit, 0, sizeof(visit));
		memset(visroute, 0, sizeof(visroute));
		if(c >= 0 && c <= 6){
			cout << dfs(x, y) << endl;
		}
		if(c >= 7 && c <= 11){
			// 2 directions.
			// 1st one.
			ll now_route = inv_a[x][0];
			ll now_stat = x;
			ll T1 = w1[x] + w1[y];
			ll T2 = w1[x] + w1[y];
			while(now_stat != y){
				ll stat = a[now_route][0];
				if(stat == now_stat) stat = a[now_route][1];
				T1 += 2 * w2[stat];
				ll route = inv_a[stat][0];
				if(route == now_route) route = inv_a[stat][1];
				now_route = route;
				now_stat = stat;
			}
			// 2nd one.
			now_route = inv_a[x][1];
			now_stat = y;
			while(now_stat != x){
				ll stat = a[now_route][0];
				if(stat == now_stat) stat = a[now_route][1];
				T2 += 2 * w2[stat];
				ll route = inv_a[stat][0];
				if(route == now_route) route = inv_a[stat][1];
				now_route = route;
				now_stat = stat;
			}
			cout << min(T1, T2) << endl;
		}
		if(c >= 12 && c <= 19){
			
		}
	}
	
	
	return 0;
}


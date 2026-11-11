#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll N = 505, M = 500005;

struct Nd{
	ll id, sum;
}; 
ll c, n, m, d, Q, w[M], k[N], x, y;
vector<ll> a[N], t[N];
vector<pi> mp[N];
queue<Nd> q;
ll vis[M];

ll bfs(ll st, ll ed){
//	printf("st = %d, ed = %d\n", st, ed);
	ll res = 1e17;
	memset(vis, 0x5f, sizeof(vis));
	vis[st] = true;
	q.push((Nd){st, 0});
	
	while(!q.empty()){
		Nd u = q.front(); q.pop();
//		printf("id = %d, sum = %d\n", u.id, u.sum);
		if(u.id == ed){
			res = min(res, u.sum);
//			printf("-------u.sum = %d, res = %d\n", u.sum, res);
			continue;
		}
		for(ll i = 0; i < mp[u.id].size(); ++ i){
			ll vi = mp[u.id][i].first, vj = mp[u.id][i].second;
//			printf("i = %d, vi = %d, vj = %d, k = %d\n", i, vi, vj, k[vi]);
			for(ll j = 0; j < k[vi]; ++ j){
//				printf("i = %d, j = %d\n", i, j);
				ll v = a[vi][j];
//				printf("v = %d\n", v);
				if(vis[v] <= u.sum + t[vi][vj] + t[vi][j])
					continue;
				vis[v] = u.sum + t[vi][vj] + t[vi][j];
				q.push((Nd){v, u.sum + t[vi][vj] + t[vi][j]});
//				printf("--j = %d, v = %d, newsum = %d\n", j, v, u.sum + t[vi][vj] + t[vi][j]);
			}
		}
	}
	return res;
} 
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> Q;
	for(ll i = 1; i <= m; ++ i){
		cin >> w[i];
	}
	
	for(ll i = 1; i <= n; ++ i){
		cin >> k[i];
		for(ll j = 0; j < k[i]; ++ j){
			ll ta, tt;
			cin >> ta >> tt;
			a[i].push_back(ta), t[i].push_back(tt);
			mp[ta].push_back((pi){i, j});
		}
	}
	
//	printf("mp = \n");
//	for(int i = 1; i <= m; ++ i){
//		cout << i << endl;
//		for(int j = 0; j < mp[i].size(); ++ j)
//			cout << mp[i][j].first << ' ' << mp[i][j].second << endl;
//		cout << endl;
//	}
	
	while(Q --){
		cin >> x >> y;
		cout << bfs(x, y) + w[x] + w[y] << endl;
	}
	return 0;
}

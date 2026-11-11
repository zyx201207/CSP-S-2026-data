#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

void fast_io(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
}

const ll kMaxN = 5e4 + 507;
const ll inf = 0x3f3f3f3f;

struct node{
	ll v , w;
	bool operator<(const node & a) const{
		return w > a.w;
	}
};

long long dis[kMaxN];
bool vis[kMaxN];

vector<node> g[kMaxN];

ll c , n , m , d , q;

void init(){
	for(int i = 0 ; i <= n + m ; i++) dis[i] = inf , vis[i] = 0;
}

ll dijkstra(ll s , ll t){
	init();
	dis[s] = 0;
//	queue<ll> que;
	priority_queue<node> que;
	que.push({s,0});
	while(!que.empty()){
		node f = que.top();
		ll u = f.v , d = f.w;
		if(vis[u]) continue;
		vis[u] = 1;
		que.pop();
		for(auto v : g[u]){
			if(dis[v.v] > dis[u] + v.w) {
				dis[v.v] = dis[u] + v.w;
				que.push({v.v,dis[v.v]});
			}
		}
	}
	return dis[t];
}

ll p[kMaxN];
long long F[kMaxN][507];

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i = 1 ; i <= m ; i++) cin>>p[i];
	for(int i = 1 ; i <= n ; i++){
		ll k;
		cin>>k;
		for(int j = 1 ; j <= k ; j++){
			ll a , t;
			cin>>a>>t;
			g[a].push_back({i + m , t});
			g[i + m].push_back({a , t});
		}
	}
	for(int i = 1 ; i <= n ; i++){
		dijkstra(i + m , 1);
		for(int j = 1 ;  j <= m ; j++) F[j][i] = (F[j][i] == 0 ? dis[j] : min(F[j][i] , dis[j]));
	}
	for(int i = 1 ; i <= q ; i++){
		ll s , t;
		cin>>s>>t;
//		cout<<p[s]+p[t]+dijkstra(s,t)<<"\n";
		long long sum = inf;
		for(int j = 1 ; j <= n ; j++) sum = min(sum , F[s][j] + F[t][j]);
		cout<<(sum+p[s]+p[t])<<"\n"; 
//		cout<<F[j][i] + p[s] + p[t];
//		cout<<dijkstra(s , t) + p[s] + p[t]/<<"\n";
	}
//	for(int i = 1 ; i <= q ; i++){
//		ll s , t;
//		cin>>s>>t;
//		cout<<p[s] + p[t] + dijkstra(s , t)<<"\n";
//	}
}

int main(){
	fast_io();
//	cout<<sizeof(g);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	solve();
	return 0;
}


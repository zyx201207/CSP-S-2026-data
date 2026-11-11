#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr<< #x << " = " << x << endl)

constexpr int N = 15086 , M = 1e6 + 86;
ll T , n , m , d , q;

// 链式前向星
struct node{
	ll next , to , w;
}edge[M << 1];
ll cnt , first[N];
inline void add(ll u , ll v , ll w){
	cnt++;
	edge[cnt].to = v;
	edge[cnt].next = first[u];
	edge[cnt].w = w;
	first[u] = cnt;
}

ll dis[N];
typedef pair<ll,ll> p;
priority_queue<p , vector<p>, greater<p> > que;
inline ll dij(ll s , ll t){
	// init
	while(!que.empty()) que.pop();
	for(ll i = 1;i <= (d + 2) * n;i++) dis[i] = INT_MAX;
	dis[s] = 0;
	que.emplace(dis[s] , s);
	while(!que.empty()){
		auto [d , u] = que.top();
		que.pop();
		if(d != dis[u]) continue;
		for(ll i = first[u];i;i = edge[i].next){
			ll v = edge[i].to , w = edge[i].w;
			if(dis[v] > d + w){
				dis[v] = d + w;
				que.emplace(dis[v] , v);
			}
		}
	}
	return dis[t];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);

	cin >> T >> m >> n >> d >> q; // 这里我将 n 和 m 互换
	// 口与厅
	for(ll i = 1 , w;i <= n;i++){
		cin >> w;
		add(i , n + i , w);
		add(n + i , i , w);
	}
	for(ll i = 1 , k , a , last , t;i <= m;i++){
		cin >> k;
		for(ll j = 1;j <= k;j++){
			cin >> a >> t;
			// 厅与台
			add(n + a , (i + 1)*n + a , t);
			add((i + 1)*n + a , n + a , t);
			// 上一站的台与这一站的台
			if(j != 1){
				add((i + 1)*n + last , (i + 1)*n + a , 0);
				add((i + 1)*n + a , (i + 1)*n + last , 0);
			}
			last = a;
		}
	}
	ll s , t;
	while(q--){
		cin >> s >> t;
		cout << dij(s , t) << endl;
	}

	return 0;
}

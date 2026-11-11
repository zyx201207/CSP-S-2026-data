#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 0x3f3f3f3f;
ll c , n , m , qq , d , k = -1 , h[500005] , dis[500005] , kt[500005] , vis[500005] , xl[25][500005];
typedef pair <ll , ll> pii;
priority_queue<pii , vector<pii> , greater<pii> > q;
struct r {
	ll v , w , ne;
} e[500005];
void add(ll v , ll u , ll wei) {
	e[k].v = v;
	e[k].w = wei;
	e[k].ne = h[u];
	h[u] = k++;
}
void dij(ll x) {
	for(int i = 1 ; i <= m ; i++) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[x] = 0;
	q.push({dis[x] , x});
	while(!q.empty()) {
		ll u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u] ; i != -1 ; i = e[i].ne) {
			ll v = e[i].v , f = 0;
			
				if(dis[v] > dis[u] + e[i].w) {
					dis[v] = dis[u] + e[i].w;
					q.push({dis[v] , v});
				
			}
		}
	}
}
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	memset(h , -1 , sizeof(h));
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1 ; i <= m ; i++) {
		cin >> kt[i];
	}
	for(int i = 1 ; i <= n ; i++) {
		ll kk , a , t , aa , tt;
		cin >> kk;
		for(int j = 1 ; j <= kk ; j++) {
			if(j == 1) {
				cin >> a >> t;
				xl[kk][a] = 1;
			} else {
				cin >> aa >> tt;
				xl[kk][aa] = 1;
				add(a , aa , tt + t);
				add(aa , a , t + tt);
				a = aa;
				t = tt;
			}
		}
	}
	for(int i = 1 ; i <= qq ; i++) {
		ll x , y;
		cin >> x >> y;
		dij(x);
		cout << dis[y] + kt[x] + kt[y]<< "\n";
	}
	return 0;
}
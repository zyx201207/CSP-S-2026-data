#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val[500009] , mn[509][509] , mx;
int vst[500009];
ll c , n , m , d , q , l , r;
vector<ll> to[501000] , w[501000];
struct node{
	ll dis , p;
	bool operator>(const node&b)const{
		return dis > b.dis;
	}
};
void dijkstra(ll id){
	memset(vst,0,sizeof(vst));
	priority_queue<node,vector<node>,greater<node> > pq;
	pq.push((node){0,id+m});
	while(!pq.empty()){
		ll u = pq.top().p;
		pq.pop();
		vst[u] = 0;
		for(ll i = 0; i < to[u].size(); i++){
			ll v = to[u][i];
			for(ll j = 0; j < to[v].size(); j++){
				ll z = to[v][j];
				if(mn[id][z-m] > mn[id][u-m] + w[u][i] + w[v][j]){
					mn[id][z-m] = mn[id][u-m] + w[u][i] + w[v][j];
					mn[z-m][id] = mn[id][u-m] + w[u][i] + w[v][j];
					if(vst[z-m] == 1) continue;
					pq.push((node){mn[id][z-m],z});
					vst[z-m] = 1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++){
		cin >> val[i];
	}
	for(ll i = 1,nm; i <= n; i++){
		cin >> nm;
		for(ll j = 1,x,y; j <= nm; j++){
			cin >> x >> y;
			to[x].push_back(m+i);
			w[x].push_back(y);
			to[m+i].push_back(x);
			w[m+i].push_back(y);
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(i == j) mn[i][j] = 0;
			else{
				mn[i][j] = 1e17;
			}
		}
	}
	for(ll i = 1; i < n; i++){
		dijkstra(i);
	}
	while(q--){
		cin >> l >> r;
		mx = 1e17;
		for(ll i = 0; i < to[l].size(); i++){
			for(ll j = 0; j < to[r].size(); j++){
				mx = min(mx,mn[to[l][i]-m][to[r][j]-m]+w[l][i]+w[r][j]);
				if(mx == 0) break;
			}
			if(mx == 0) break;
		}
		mx += val[l] + val[r];
		cout << mx << '\n';
	}
	return 0;
}

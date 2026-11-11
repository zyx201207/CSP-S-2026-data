#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct po{
	int v,w;
	bool friend operator < (po a,po b){
		return a.w > b.w;
	}
};
const int L = 5e5+5e2+5;
int dis[L];
int c,n,m,d,q;
int w[L];
bool f[L];
vector<po> G[L];
void sub6(){
	for (int i = 1;i <= n;++i){
		int p = m+i;
		int k;
		cin >> k;
		for (int j = 1;j <= k;++j){
			int a,t;
			cin >> a >> t;
			G[p].push_back({a,t});
			G[a].push_back({p,t});
		}
	}
	int N = m+n;
	while (q--){
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= N;++i) dis[i] = 0x3f3f3f;
		priority_queue<po> pq;
		pq.push({x,0});
		dis[x] = 0;
		while (!pq.empty()){
			int u = pq.top().v;
			pq.pop();
			if (u == y){
				cout << dis[u]+w[x]+w[y] << '\n';
				break;
			}
			for (int i = 0;i < G[u].size();++i){
				int v = G[u][i].v,w = G[u][i].w;
				if (dis[v] > dis[u]+w){
					dis[v] = min(dis[v],w+dis[u]);
					pq.push({v,dis[v]});	
				}
			}
		}
	}
}
void sub11(){
	for (int i = 1;i <= n;++i){
		int k;
		cin >> k;
		if (k != 2) continue;
		int a1,t1,a2,t2;
		cin >> a1 >> t1 >> a2 >> t2;
		G[a1].push_back({a2,t1+t2});
		G[a2].push_back({a1,t1+t2});
	}
	int N = m;
	while (q--){
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= N;++i) dis[i] = 0x3f3f3f;
		priority_queue<int> pq;
		pq.push(x);
		dis[x] = 0;
		while (!pq.empty()){
			int u = pq.top();
			pq.pop();
			if (u == y){
				cout << dis[u]+w[x]+w[y] << '\n';
				break;
			}
			for (int i = 0;i < G[u].size();++i){
				int v = G[u][i].v,w = G[u][i].w;
				if (dis[v] > dis[u]+w){
					dis[v] = min(dis[v],w+dis[u]);
					pq.push(v);	
				}
			}
		}
	}
}
void sub19(){
	for (int i = 1;i <= n;++i){
		int p = m+i;
		int k;
		cin >> k;
		for (int j = 1;j <= k;++j){
			int a,t;
			cin >> a >> t;
			G[p].push_back({a,0});
			G[a].push_back({p,0});
		}
	}
	int N = m+n;
	while (q--){
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= N;++i) f[i] = 0,dis[i] = 0x3f3f3f;
		queue<int> pq;
		pq.push(x);
		f[x] = 1;
		dis[x] = 0;
		while (!pq.empty()){
			int u = pq.front();
			pq.pop();
			if (u == y){
				cout << dis[u]+w[x]+w[y] << '\n';
				break;
			}
			for (int i = 0;i < G[u].size();++i){
				int v = G[u][i].v;
				if (!f[v]){
					dis[v] = dis[u]+1;
					pq.push(v);	
					f[v] = 1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;++i) cin >> w[i];
	if (c <= 6){
		sub6();
	}else if (c <= 11){
		sub11();
	}else{
		sub19();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int c,n,m,d1,q;
struct edge{
	int line;
	long long t;
	int v;
};
vector<edge> g[N];
int a[N];
long long dis[N];
long long ti[N]; 

long long ans[N];

struct node{
	int id;
	int line;
	long long d;
	long long t;
};
bool operator < (node x, node y){
	return x.d > y.d;
}
bool vis[N];

void dj(int s){
	memset(dis,0x3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s] = 0;
	priority_queue<node> q;
	q.push({s,0,0,0});
	while(!q.empty()){
		node cur = q.top();
		q.pop();
		int u = cur.id;
		int l1 = cur.line;
		long long t1 = cur.t;
		if (vis[u]) continue;
		vis[u] = 1;
		ti[u] = t1;
		for (edge ed : g[u]){
			int v = ed.v;
			int l2 = ed.line;
			long long t = ed.t;
			long long w = 0;
			if (l1 != l2){
				w += t1;
			}
			if (dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({v,l2,dis[v],t});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d1 >> q;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int pre = 0;
		long long pre_t = 0;
		for (int j = 1; j <= k; j++){
			int u;
			long long t;
			cin >> u >> t;
			g[pre].push_back({i,t,u});
			g[u].push_back({i,pre_t,pre});
			pre = u;
		}
	}
	for (int i = 1; i <= q; i++){
		int s,f;
		cin >> s >> f;
		dj(s);
		cout << dis[f] + ti[f] + a[s] + a[f] << endl;
	}
	return 0;
}

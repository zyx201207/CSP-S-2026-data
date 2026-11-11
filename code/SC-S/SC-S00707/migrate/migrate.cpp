#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
long long jc[5005], vis[5005], dist[5005], ans, m[5005], n, c, d, t,num[5005];
struct edge {
	long long v, w;
};
vector<edge> a[5005];
struct node {
	long long to, dist;
	operator <(node x)const {
		return x.dist < dist;
	}
};
priority_queue<node> q;
void dij(long long s) {
	for (int i = 1; i <= 5000; i++) {
		dist[i] = INF;
		vis[i] = 0;
		num[i] = 0;
	}
	q.push({s, 0});
	//vis[s]=1;
	while (!q.empty()) {
		long long u = q.top().to, dis = q.top().dist;
		q.pop();
		if (vis[u]) continue;
		for (int i = 0; i < a[u].size(); i++) {
			long long v = a[u][i].v, w = a[u][i].w;
			vis[u] = 1;
			if (dist[v] == dis + w) {
				num[v]++;
			}
			if (dist[v] > dis + w) {
				num[v]=1;
				dist[v] = dis + w;
				q.push({v, dis + w});
			}
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>m[i];
			while(!a[i].empty()) a[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long w=abs(m[i]-m[j]);
				if(w<=d){
					a[i].push_back({j,1});
					a[j].push_back({i,1});
				}
				
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(num[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 20 
1 2 3 4 5

*/
#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
long long jc[5005], vis[5005], dist[5005], ans, m, n, c, d, t;
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
	}
	q.push({s, 0});
	//vis[s]=1;
	while (!q.empty()) {
		long long u=q.top().to,dis=q.top().dist;
		q.pop();
		if(vis[u]) continue;
		for(int i=0;i<a[u].size();i++){
			long long v=a[u][i].v,w=a[u][i].w;
			vis[u]=1;
			if(dist[v]>dis+w){
				dist[v]=dis+w;
				q.push({v,dis+w});
			}
		}
	}
}
struct que{
	long long x,y,num,ans;
};
que qq[500005];
bool cmp(que q,que e){
	return q.x<e.x;
}
bool cmp2(que q,que e){
	return q.num<e.num;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> t;
	for (int i = 1; i <= m; i++) {
		cin >> jc[i];
	}
	for (int i = 1; i <= n; i++) {
		long long k, b[1005], w[1005];
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> b[j] >> w[j];
			a[b[j]].push_back({m + i, w[j]});
			a[m + i].push_back({b[j], w[j]});
		}
	}
	for(int i=1;i<=t;i++){
		cin>>qq[i].x>>qq[i].y;
		qq[i].num=i;
	}
	sort(qq+1,qq+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(qq[i].x!=qq[i-1].x) dij(qq[i].x);
		qq[i].ans=dist[qq[i].y]+jc[qq[i].x]+jc[qq[i].y];
	}
	sort(qq+1,qq+t+1,cmp2);
	for(int i=1;i<=t;i++){
		cout<<qq[i].ans<<endl;
	}
	return 0;
}/*
建图：地铁线路和车站为点
车站按编号
线路为m+i号

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
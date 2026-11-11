#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,D,q,T,w[M],d[N][N],dis[N][N];bool vis[N];
vector<pair<int,int>> sta[N],met[M],g[N];//metro->station || station->metro
priority_queue<pair<int,int>> pque;
void Smin(int &a,int b) {a=min(a,b);}
void Dijkstra(int s) {
	memset(dis[s],0x3f,sizeof dis[s]);
	memset(vis,false,sizeof vis);
	while (!pque.empty()) pque.pop();
	pque.push({dis[s][s]=0,s});
	while (!pque.empty()) {
		int u=pque.top().second;pque.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (pair<int,int> p:g[u]) {
			int v=p.first,w=p.second;
			if (vis[v]) continue;
			if (dis[s][v]>dis[s][u]+w) {
				dis[s][v]=dis[s][u]+w;
				pque.push({-dis[s][v],v});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&q);
	for (int i=1; i<=m; i++) scanf("%lld",w+i);
	for (int i=1,k; i<=n; i++) {
		scanf("%lld",&k);
		for (int j=0,a,t; j<k; j++) {
			scanf("%lld%lld",&a,&t),T=t;
			sta[i].emplace_back(a,t);
			met[a].emplace_back(i,t);
		}
	}
	memset(d,0x3f,sizeof d);
	if (c>=12 && c<=19) {//B
		for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) d[i][j]=T*2;
	}else for (int i=1; i<=m; i++)
	for (pair<int,int> j:met[i])
	for (pair<int,int> k:met[i]) {
//		cerr<<"RE";
		Smin(d[j.first][k.first],j.second+k.second);
		Smin(d[k.first][j.first],j.second+k.second);
	}
	for (int i=1; i<=n; i++) d[i][i]=0;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		if (d[i][j]<1e18 && i!=j) g[i].emplace_back(j,d[i][j]);
	for (int i=1; i<=n; i++) Dijkstra(i);
	for (int i=0,x,y; i<q; i++) {
		int res=1e18;scanf("%lld%lld",&x,&y);
		for (pair<int,int> j:met[x])
		for (pair<int,int> k:met[y])
			res=min(res,dis[j.first][k.first]+j.second+k.second);
		printf("%lld\n",res+w[x]+w[y]);
	} 
	return 0;
}
/*
a graph problem.
first.from x to y,the w[] is useless
we add w[x]+w[y] to ans then w[] useless.
we have a graph,and vertex has a weight.
nonono. we shall no do this.
every metro is a vertex.
and every station is a vertex.
every metro connets a t[i][j]-weighed edge to a station
we want to know the shortest route from station to station
we see only 500 metros, but 5e5 stations.
wait. every station only 20 metros.
so we have 1e8 edges from metros to stations to metros.
we cant see these edges fully.
how can we get these edges?
but wait,only 2.5e5 edges is useful.
let's turn all station edges to metro edges.
but how???? we have 1e8 edges.this is BAD.
1e7 edges,we can only see these,we cant see 1e8.
this time,we need some DS?no we cant get even LOG.
maybe we can div&conq.nonono.we cant.
cant turn,but we can get a min cost for i to get to station.
hmmm...
oh wait,the machine can run 1e8!i remember.so this is okay
so if we can see the all 1e7 edges,and see d[i][j].
then floyd, easy.
but floyd is 1.25e8.
so we shall Dijkstra n points,it's n^2 log n
then it's okay.
so we can know shortest route from metro A to metro B.
then,for every Q(x,y),we calc every metro that can reach x,and reach y
ans=w[x]+w[y]+dis[metrox][metroy]+t[x-metrox][y-metroy]
time complexity is O(md^2+qd^2+n^2log n+n^3)
no.... Dij not faster than Floyd!!!
maybe we write a B? 
let's go! 
*/

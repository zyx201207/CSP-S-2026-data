#include <bits/stdc++.h>
using namespace std;
const int N = 1010,Q = 1e5 + 10,M = 6e5 + 10;
int c,n,m,d,q,w[M];
bool vis[M];
long long ans[Q];
long long dis[M];
struct qq{
	int x,y,id;
}ql[Q];
vector <int> g[M];
vector <long long> gw[M];
inline int ge(int id1,int id2){
	return (id1 - 1) * m + id2;
}
inline void ade(int u,int v,int w){
	g[u].push_back(v),g[v].push_back(u);
	gw[u].push_back(w),gw[v].push_back(w);
}
priority_queue <pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
inline bool cmp(qq a,qq b){
	if(a.x == b.x){
		if(a.y == b.y)
			return a.id < b.id;
		return a.y < b.y;
	}return a.x < b.x;
}
inline pair<long long,int> pii(long long a,int b){
	pair<long long,int> ttt;
	ttt.first = a,ttt.second = b;
	return ttt;
}
inline void dij(int s){
	for (int i = 0;i < M;i++) dis[i] = LLONG_MAX;
	memset(vis,0,sizeof(vis));
	pq.push(pii(0,s));
	dis[s] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		int len = g[u].size();
		for (int i = 0;i < len;i++){
			int v = g[u][i];long long w = gw[u][i];
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push(pii(dis[v],v));
			}
		}		
	}
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for (int i = 1;i <= n;i++){
		int k;scanf("%d",&k);
		int t1,a1;scanf("%d%d",&a1,&t1);
		ade(a1,ge(i + 1,a1),t1);
		for (int j = 2;j <= k;j++){
			int t,a;scanf("%d%d",&a,&t);
			ade(ge(i + 1,a),ge(i + 1,a1),0);
			ade(a,ge(i + 1,a),t);
		}
	}for (int i = 1;i <= q;i++){
		scanf("%d%d",&ql[i].x,&ql[i].y);
		if(ql[i].x > ql[i].y) swap(ql[i].x,ql[i].y);
		ql[i].id = i;
	}sort(ql + 1,ql + q + 1,cmp);
	int las = -1;
	for (int i = 1;i <= q;i++){
		int x = ql[i].x,y = ql[i].y,id = ql[i].id;
		if(x != las) dij(x),las = x;
		ans[id] = dis[y] + w[x] + w[y];
	}for (int i = 1;i <= q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}


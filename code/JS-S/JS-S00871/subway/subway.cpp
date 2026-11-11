/*
 * 17:02 v1 O(q(sumk)log(sumk)) 32~60pts
 * sample 2,3 pass
 * sample 1 segment fault but answer correct
 * try-catch no result
 * God bless whatever
 * 18:03 fix
 */
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
using namespace std;
using node=pair<int,int>; //2byte
using edge=pair<node,int>;//3byte
using dijk=pair<int,node>;//3byte
const int N=505;
const int M=500005;
int c,n,m,d,q,_[M];
map<node,int> dist;
map< node,vector<edge> > g;
void dijkstra(node s){
	priority_queue< dijk,vector<dijk>,greater<dijk> > pq;
	pq.push({0,s});
	dist[s]=0;
	while (!pq.empty()){
		int d=pq.top().first;
		node u=pq.top().second;
		pq.pop();
		if (dist[u]!=d) continue;
		for (edge e:g[u]){
			node v=e.first;
			int w=e.second;
			if (!dist.count(v) || dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push(mp(dist[v],v));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> _[i];
	for (int i=1,k;i<=n;i++){
		cin >> k;
		vector<int> a(k+1);
		for (int j=1,t;j<=k;j++){
			cin >> a[j] >> t;
			g[{a[j],i}].push_back({{a[j],0},t});
			g[{a[j],0}].push_back({{a[j],i},t});
		}
		for (int j=1;j<k;j++){
			g[{a[j],i}].push_back({{a[j+1],i},0});
			g[{a[j+1],i}].push_back({{a[j],i},0});
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		dist.clear();
		dijkstra({x,0});
		cout << dist[{y,0}]+_[x]+_[y] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;
typedef long long ll;
struct Edge{
	int to;
	ll w;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	if(!(cin >> c >> n >> m >> d >> q)) return 0;
	vector<ll> w(m+1);
	for(int i=1;i<=m ;++i) cin >>w[i];
	vector<vector<Edge> > g(m+n+1);
	for(int i=1;i<=n;++i){
		int k;
		cin >> k;
		int line_node = m+i;
		for(int j=0;j<k;++j){
			int st;
			ll t;
			cin >> st >> t;
			Edge e1,e2;
			e1.to=line_node;e1.w=t;
			g[line_node].push_back(e1);
			e2.to=st;e2.to = t;
			g[line_node].push_back(e2);
		}
	}
	for(int i=0;i<q;++i){
		int x,y;
		cin >> x >> y;
		vector<ll>dist(m+n+1,1e18);
		vector<bool>inq(m+n+1,false);
		queue<int>Q;
		dist[x] = 0;
		Q.push(x);
		inq[x] = true;
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			inq[u]=false;
			for(int j=0;j<=g[u].size();++j){
				int v=g[u][j].to;
				ll weight=g[u][j].w;
				if(dist[u]+weight<dist[v]){
					dist[v]=dist[u]+weight;
					if(!inq[v]){
						Q.push(v);
						inq[v] = true;
					}
				}
			}
		}
		cout <<w[x] << endl <<+dist[y]+w[y]<< "\n" ;			
	}
	return 0;
}

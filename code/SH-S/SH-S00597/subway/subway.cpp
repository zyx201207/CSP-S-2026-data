#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,dis[1000510];
vector<pair<int,int> >G[1000510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for (int i=1,x;i<=m;i++){
		cin>>x;
		G[i*2-1].push_back(make_pair(i*2,x));
		G[i*2].push_back(make_pair(i*2-1,x));
	}
	for (int i=1,sum;i<=n;i++){
		cin>>sum;
		for (int j=1,a,t;j<=sum;j++){
			cin>>a>>t;
			G[a*2].push_back(make_pair(m*2+i,t));
			G[m*2+i].push_back(make_pair(a*2,t));
		}
	}
	while (Q--){
		memset(dis,0x3f3f3f,sizeof(dis));
		int x,y;
		cin>>x>>y;
		dis[x*2-1]=0;
		priority_queue<pair<int,int> >pq;
		pq.push(make_pair(0,x*2-1));
		while (pq.size()){
			pair<int,int> s=pq.top();
			pq.pop();
			int now=s.first,u=s.second;
			for (int i=0;i<G[u].size();i++){
				int v=G[u][i].first,w=G[u][i].second;
				if (dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push(make_pair(dis[v],v));
				}
			}
		}
		cout<<dis[y*2-1]<<endl;
	}
	return 0;
}

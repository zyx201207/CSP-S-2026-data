#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
vector<pair<int,int> >g[N];
int DIJ(int x,int y){
	vector<int> dis(505,1e18);
	vector<bool> vis(505,0);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			pair<int,int> t=g[u][i];
			if(dis[u]+t.first<dis[t.second]){
				dis[t.second]=dis[u]+t.first;
				pq.push({dis[t.second],t.second});
			}
		}
	}
	return dis[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int v;
		cin>>v;
		g[i].push_back({v,i+m});
		g[i+m].push_back({v,i});
	}
	int cnt=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> ve(k+5,0);
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			g[u+m].push_back({v,++cnt});
			g[cnt].push_back({v,u+m});
			ve[j]=cnt;
		}
		for(int j=1;j<k;j++){
			g[ve[j]].push_back({0,ve[j+1]});
			g[ve[j+1]].push_back({0,ve[j]});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<DIJ(x,y)<<"\n";
	}
	return 0;
}
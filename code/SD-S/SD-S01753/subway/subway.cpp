#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[501000],dis[501000],vis[501000];
vector<pair<int,int> >e[501000];
void dij(int s){
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]==1){
			continue;
		}
		vis[x]=1;
		for(auto v:e[x]){
			if(dis[v.first]>dis[x]+v.second){
				dis[v.first]=dis[x]+v.second;
				q.push({dis[v.first],v.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	if(7<=c<=11){
		for(int i=1;i<=n;++i){
			int op,u,v,w1,w2;
			cin>>op;
			if(op==2){
				cin>>u>>w1>>v>>w2;
				e[u].push_back({v,w1});
				e[v].push_back({u,w2});
			}else if(op==1){
				cin>>u>>w1;
			}else{
				continue;
			}
		}
		while(q--){
			int s,t;
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
			cin>>s>>t;
			for(int i=1;i<=m;++i){
				dis[i]=1e18;
				vis[i]=0;
			}
			q.push({0,s});
			dis[s]=0;
			dij(s);
			cout<<w[s]+w[t]+dis[t]<<"\n";
		}
	}else{
		int u[510][510],t[510][510];
		for(int i=1;i<=n;++i){
			int k;
			cin>>k;
			for(int j=1;j<=k;++j){
				cin>>u[i][j]>>t[i][j];
			}
			for(int j=1;j<=k;++j){
				for(int x=1;x<=k;++x){
					e[u[i][j]].push_back({u[i][x],t[i][j]});
					e[u[i][x]].push_back({u[i][j],t[i][x]});
				}
			}
		}
		while(q--){
			int s,t;
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
			cin>>s>>t;
			for(int i=1;i<=m;++i){
				dis[i]=1e18;
				vis[i]=0;
			}
			q.push({0,s});
			dis[s]=0;
			dij(s);
			cout<<w[s]+w[t]+dis[t]<<"\n";
		}
	}
}

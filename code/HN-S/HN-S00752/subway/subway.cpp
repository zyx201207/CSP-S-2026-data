#include<bits/stdc++.h>
using namespace std;
#define int long long
int op,n,m,s,qq,a[500003],u,v,w,k,x,y,ans;
vector<pair<int,int> >g[600003];
map<pair<int,int>,int>d;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>n>>m>>s>>qq;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>w;
			g[u].push_back({m+i,w});
			g[m+i].push_back({u,w}); 
		//	cout<<u<<" "<<i+m<<"\n";
		}
	}
	for(int i=m+1;i<=n+m;i++){
		for(int j=1;j<=m+n;j++){
			d[{i,j}]=1e18;				
		}
		d[{i,i}]=0;
		q.push({0,i});
		while(q.size()){
			u=q.top().second;
			x=q.top().first;
			q.pop();
			if(x>d[{i,u}]){
				
				continue;
			}
			for(int j=0;j<g[u].size();j++){
				v=g[u][j].first;
				w=g[u][j].second;
				if(d[{i,u}]+w<d[{i,v}]){
					d[{i,v}]=d[{i,u}]+w;
					q.push({d[{i,v}],v});
				}
			}
		}
	} 
	while(qq--){
		cin>>x>>y;
		int minn=1e18;
		for(int i=m+1;i<=n+m;i++){
			minn=min(minn,d[{i,x}]+d[{i,y}]);	
		}
		cout<<minn+a[x]+a[y]<<"\n";
	}
	return 0;
} 

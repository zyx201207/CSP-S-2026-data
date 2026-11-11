#include<bits/stdc++.h>
using namespace std;
int c,n,d,p;
long long m;
vector<pair<int,int> >g[506];
long long dis[506][506];
int vis[506][506];
int x[506];
void dfs(int rt){
    priority_queue<pair<long long,int> > q;
		
			for(int j=1;j<=n;j++){
				dis[rt][j]=1e18;
				vis[rt][j]=0;
		}
		dis[rt][rt]=0;
		q.push({0ll,rt});
	while(!q.empty()){
		int u=q.top().second;
		long long w=q.top().first*(-1);
		q.pop();
	    if(vis[rt][u]==1) continue;
	    else{
	    	vis[rt][u]=1;
	    	for(int i=0;i<g[u].size();i++){
	    		//cout<<11;
	    		int v=g[u][i].first,w1=g[u][i].second;
	    		//cout<<v<<' '<<w1<<endl;
	    		if(w1+w<dis[rt][v]){
	    			dis[rt][v]=w1+w;
	    			//cout<<dis[rt][v]<<" ";
	    			q.push({-dis[rt][v],v});
				}
			}
		}
	}
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    if(c>=7&&c<=11){
    	for(int i=1;i<=m;i++){
    		cin>>x[i];
    		//g[0].push_back({i,a});
		}
		for(int i=1;i<=n;i++){
			//cout<<1111111;
			int k;
			cin>>k;
			int a[6],b[6];
			for(int j=1;j<=k;j++){
				//int a,b;
				cin>>a[j]>>b[j];
			}
			g[a[1]].push_back({a[2],b[1]+b[2]});
			g[a[2]].push_back({a[1],b[1]+b[2]});
		}
		for(int i=1;i<=n;i++){
			dfs(i);
			//cout<<1;
		}
		for(int i=1;i<=p;i++){
			int a,b;
			cin>>a>>b;
			cout<<dis[a][b]+x[a]+x[b]<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,n,m,p,q;
int w[N];//第i个站台的离开代价
int dis[N][N];//i,j直达的最小代价 
vector<pair<int,int>> a[N];
int ct[N];//从x到i的最小代价 
int ans=0;
int d[N],vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>p>>q;
	//cout<<"out";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u,v,t1,t2;
		cin>>u>>t1>>v>>t2;
		dis[u][v]=min(dis[u][v],t1+t2);
	}
	priority_queue<pair<int,int>,vector<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]!=INT_MAX){
				a[i].push_back({dis[i][j],j});
			}
		}
	}
	while(q--){
		int x;int y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			d[i]=INT_MAX;
			vis[i]=0;
		}
		d[x]=0;
		q.push({0,x});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=0;i<a[u].size();i++){
				int v=a[u][i].second;
				int w=a[u][i].first;
				if(w+d[u]<=d[v]){
					d[v]=w+d[u];
					q.push({d[v],v});
				}
			}
		}
		cout<<w[x]+w[y]+d[y]<<endl;
	}
	return 0;
}


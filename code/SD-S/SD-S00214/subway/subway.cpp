#include<iostream>
#include<vector> 
#include<cstdio>
using namespace std;
const long long inf=1e18;
long long w[500005];
vector<pair<int,long long>>g[500005];
long long f[505][505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
   freopen("subway.in","r",stdin);
   freopen("subway1.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int u;
			long long t;
			cin>>u>>t;
			g[u].push_back({i,t});
			 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		f[i][j]=1e18;
		f[i][i]=0;
		
	}
	for(int u=1;u<=m;u++){
		 int s=g[u].size();
		 for(int i=0;i<s;i++)
		 for(int j=0;j<s;j++){
		int x=g[u][i].first,y=g[u][j].first;
		long long v=g[u][i].second+g[u][j].second;
		if(v<f[x][y])f[x][y]=v;
		 	}		
		 }
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(f[i][k]+f[k][j]<f[i][j])
	f[i][j]=f[i][k]+f[k][j];
	while(q--){
		int x,y;
		cin>>x>>y;
		long long r=1e18;
		for(auto&i:g[x])
		for(auto&j:g[y]){
			long long t=i.second+f[i.first][i.first]+j.second;
			if(t<r)r=t;
			
			
		}
		cout<<r+w[x]+w[y]<<'\n'; 
		 
	}
	    return 0;

	}
	

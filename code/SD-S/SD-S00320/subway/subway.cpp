#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
int dist[510][510],c,n,m,d,q,w[500010];
vector<int>g[500010],tm[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			g[a].push_back(i);
			tm[a].push_back(t);
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				//cout<<"dist["<<g[i][k]<<"]["<<g[i][j]<<"]=min("<<dist[g[i][j]][g[i][k]]<<","<<tm[i][j]<<"+"<<tm[i][k]<<")\n";
				dist[g[i][k]][g[i][j]]=dist[g[i][j]][g[i][k]]=min(dist[g[i][j]][g[i][k]],tm[i][j]+tm[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,ans=1000000000000000000;
		cin>>u>>v;
		for(int j=0;j<g[u].size();j++){
			for(int k=0;k<g[v].size();k++){
				//cout<<"ans=min("<<ans<<','<<dist[g[u][j]][g[v][k]]<<")\n";
				ans=min(ans,dist[g[u][j]][g[v][k]]+tm[u][j]+tm[v][k]);
			}
		}
		cout<<w[u]+w[v]+ans<<'\n';
	}
	return 0;
} 

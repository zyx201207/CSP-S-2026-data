#include<bits/stdc++.h>
using namespace std;
long long tt[5005][5005],k[505],w[130000],vis[500005],c,n,m,d,q,sum,minn=9223372036854775806;
vector<pair<long long,long long> > edge[130000];
vector<long long> xl[505];
void dfs(long long x,long long y,long long summ){
	if(x==y){
		minn=min(minn,summ);
		return;
	}
	vis[x]=1;
	for(int i=0;i<edge[x].size();i++){
		for(int j=0;j<xl[edge[x][i].second].size();j++){
			if(!vis[xl[edge[x][i].second][j]]){
				dfs(xl[edge[x][i].second][j],y,summ+tt[x][edge[x][i].second]+tt[xl[edge[x][i].second][j]][edge[x][i].second]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
			tt[a][i]=t;
			edge[a].push_back({t,i});
			xl[i].push_back(a);
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		sum=w[x]+w[y];
		minn=9223372036854775806;
		memset(vis,0,sizeof(vis));
		dfs(x,y,0);
		cout<<sum+minn<<"\n";
	}
	return 0;
}

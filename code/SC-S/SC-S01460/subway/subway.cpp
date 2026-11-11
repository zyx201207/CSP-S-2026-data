#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,p,a[500005],u,v,vis[500005];
long long ans=1e18;
vector<int>hc[505];
vector<pair<int,int> >node[500005];
void dfs(int u,long long m,int v){
	if(u==v){
		ans=min(ans,m);
		return;
	}
	if(vis[u]==1)return;
	vis[u]=1;
	for(int i=0;i<node[u].size();i++){
		pair<int,int> x=node[u][i];
		for(int j=0;j<hc[x.first].size();j++){
			for(int k=0;k<node[hc[x.first][j]].size();k++){
				if(node[hc[x.first][j]][k].first==x.first){
					dfs(hc[x.first][j],m+x.second+node[hc[x.first][j]][k].second,v);
				}
				break;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		int k;cin>>k;
		for(int i=1;i<=k;i++){
			cin>>u>>v;
			hc[t].push_back(u);
			node[u].push_back({t,v});
		}
	}
	while(p--){
		cin>>u>>v;
		dfs(u,a[u]+a[v],v);
		memset(vis,0,sizeof vis);
		cout<<ans<<'\n';
		ans=1e18;
	}
	return 0;
}
//姓名：刘浩宇  学校：西安市汇知中学  考号：SN_S00378 
#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false);
using namespace std;
int c,n,m,d,q,a[500005],K,u,v,vis[505],ans;
vector<pair<int,int> >p[505],z[500005];
int dfs(int x,int y){
	int ans=1e15;
	if(x==y){
		return 0;
	}
	for(int i=0;i<z[x].size();i++){
		int nx=z[x][i].first,ny=z[x][i].second;
		for(int j=0;j<p[nx].size();j++){
			int tx=p[nx][j].first,ty=p[nx][j].second;
			if(vis[tx]==0){
				vis[tx]=1;
				ans=min(ans,ty+ny+dfs(tx,y));
				vis[tx]=0;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>u>>v;
			p[i].push_back({u,v});
			z[u].push_back({i,v});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=a[u]+a[v];
		memset(vis,0,sizeof(vis));
		vis[u]=1;
		ans+=dfs(u,v);
		cout<<ans<<"\n";
	}
	return 0;
}

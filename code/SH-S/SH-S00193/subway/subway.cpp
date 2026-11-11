#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
bool vis[505];
int x,y;
int t;
long long ans;
vector<int>g[505],l[505];
void dfs(int u,int ln,long long sum){
	if(u==y){
		ans=max(ans,sum+t+w[u]);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		int nxtln=l[u][i];
		if(vis[v])continue;
		vis[v]=1;
		if(nxtln==ln)dfs(v,ln,sum);
		else dfs(v,nxtln,sum+t+t);
		vis[v]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t;
			if(j==1)continue;
			g[a[i][j]].push_back(a[i][j-1]);
			g[a[i][j-1]].push_back(a[i][j]);
			l[a[i][j]].push_back(i);
			l[a[i][j-1]].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		dfs(x,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

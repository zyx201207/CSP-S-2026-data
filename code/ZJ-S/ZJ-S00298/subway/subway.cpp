#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int ans=1e9;
int w[500010];
int k[510];
int a[510][500010],t[510][500010];
int vis[500010];
vector<int> g[500010];
void dfs(int s,int e,int time){
	if(s==e){
		ans=min(ans,time);
	}
	for(int it=0;it<g[s].size();it++){
		for(int i=1;i<=k[g[s][it]];i++){
			int sum=t[g[s][it]][s]+t[g[s][it]][a[g[s][it]][i]];
			if(!vis[a[g[s][it]][i]]){
				vis[a[g[s][it]][i]]=1;
				dfs(a[g[s][it]][i],e,time+sum);
				vis[a[g[s][it]][i]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<'\n';
		ans=1e9;
	}
	return 0;
}

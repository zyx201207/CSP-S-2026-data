#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
long long ans=1e18;
int w[M];
int k[505];
int a[505][M],t[505][M];
vector<int> u[M],v[M];
bool vis[M],vis2[505];
void dfs(int now,int y,int xl,long long cost){
	if(now==y){
		ans=min(ans,cost);
		return;
	}
	vis[now]=1;
	vis2[xl]=1;
	for(auto j:v[xl]){
		if(j==y){
			dfs(j,y,xl,cost);
			break;
		}
	}
	for(auto i:u[now]){
		if(vis2[i]) continue;
		for(auto j:v[i]){
			if(vis[j]) continue;
			dfs(j,y,i,cost+t[i][now]+t[i][j]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) cin>>w[i];
	for(int i=1; i<=n; ++i){
		cin>>k[i];
		for(int j=1; j<=k[i]; ++j){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=k[i]; ++j){
			u[a[i][j]].push_back(i);
			v[i].push_back(a[i][j]);
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		int x,y;
		cin>>x>>y;
		ans=1e18;
		dfs(x,y,0,0);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}

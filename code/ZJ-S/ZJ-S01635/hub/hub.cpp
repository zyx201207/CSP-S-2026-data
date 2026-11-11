#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
vector<int>e[N];
int n,k;
int f[N];
int F[N];
int dis[N][N];
void dfs2(int id){
	F[id]=1;
	for(int to:e[id]){
		if(F[to])continue;
		dfs2(to);
	}
	return;
}
int ans;
void dfs(int id){
	if(id==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=f[i];
		if(cnt!=k)return;
		
		for(int i=1;i<=n;i++)F[i]=0;
		int cnt2=0;
		for(int i=1;i<=n;i++)if(!F[i] && f[i]){
			dfs2(F[i]);
			cnt2++;
		}
		if(cnt2>2)return;
		int mx=0;
		for(int i=1;i<=n;i++){
			int mn=1e18;
			for(int j=1;j<=n;j++)if(f[i]){
				mn=min(mn,dis[i][j]);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
		return;
	}
	f[id]=0;
	dfs(id+1);
	f[id]=1;
	dfs(id+1);
}
signed main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					
				}	
			}
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
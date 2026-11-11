#include <bits/stdc++.h>
using namespace std;

const int N=4005; 
int c,t,n,k,g[N][N],in[N],vis[N];
vector<int> e[N];

void dfs(int u){
	if(vis[u]) return ;
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(!in[v]) continue;
		dfs(v);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
			for(int j=1;j<=n;j++) g[i][j]=1e9;
			g[i][i]=0;
		}
		int ans=1e9;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u][v]=g[v][u]=1;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(g[i][j]&&g[i][k]&&g[k][j]){
						g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
					}
				}
			}
		}
		for(int mask=0;mask<(1<<n);mask++){
			int cnt=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if((mask>>i-1)&1){
					in[i]=1;
					cnt++;
				}else in[i]=0;
			}
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=1;i<=n;i++){
				if(in[i]){
					if(vis[i]) continue;
					dfs(i);
					cnt2++;
				}
			}
			if(cnt2>2) continue;
			int mx=0;
			for(int i=1;i<=n;i++){
				if(in[i]) continue;
				int mn=1e9;
				for(int j=1;j<=n;j++){
					if(!in[j]) continue;
					mn=min(mn,g[i][j]);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

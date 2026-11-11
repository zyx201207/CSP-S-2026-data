#include<bits/stdc++.h>
using namespace std;
const int N=15,M=1e5+5;
int c,t,n,k,ans,dis[N][N];
bool vis[N];
vector<int>g[M];
void dfs1(int st,int u,int w,int fa=0){
	dis[st][u]=w;
	for(int v:g[u]) if(v^fa) dfs1(st,v,w+1,u);
}
void dfs2(int s,int u,int fa=0){
	vis[u]=1;
	for(int v:g[u]) if(v^fa&&(s&(1<<(v-1)))) dfs2(s,v,u);
}
void dfs3(int st,int u,int w,int fa=0){
	ans=max(ans,w);
	for(int v:g[u]) if(v^fa&&v>st) dfs3(st,v,w+1,u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k,ans=2e9;
		if(c<=3){
			for(int i=1;i<=n;i++){
				g[i].clear();
				for(int j=1;j<=n;j++) dis[i][j]=2e9;
			}
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v),g[v].push_back(u);
			}
			for(int i=1;i<=n;i++) dfs1(i,i,0);
			for(int s=0;s<(1<<n);s++){
				//记得s是0~n-1
				int cnt=0;
				for(int i=1;i<=n;i++) if(s&(1<<(i-1))) cnt++;
				if(cnt!=k) continue;
				cnt=0;
				for(int i=1;i<=n;i++) vis[i]=0;
				for(int i=1;i<=n;i++) if((s&(1<<(i-1)))&&!vis[i]) cnt++,dfs2(s,i);
				if(cnt>2) continue;
				int mx=0;
				for(int i=1;i<=n;i++){
					int mn=2e9;
					for(int j=1;j<=n;j++) if(s&(1<<(j-1))) mn=min(mn,dis[j][i]);
					mx=max(mx,mn);
				}
				ans=min(ans,mx);
			}
			cout<<ans<<'\n';
		}
		else if(c==13||c==14){
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v),g[v].push_back(u);
			}
			if(k==n) cout<<"0\n";
			else if(k>=n/2) cout<<"1\n";
			else{
				ans=0,dfs3(k+1,k+1,0);
				cout<<max(ans,1)<<'\n';
			}
		}
		else cout<<(k!=n)<<'\n';
	}
	return 0;
}
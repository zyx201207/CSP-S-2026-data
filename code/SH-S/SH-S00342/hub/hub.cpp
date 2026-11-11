#include<bits/stdc++.h>
using namespace std;

int c,t;
const int N=1e6+10;
vector<int> g[N];
int n,k;
int u,v;
bool vis[N];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void init(){for(int i=1;i<=n;i++) fa[i]=i;}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
	return ;
}
void check(int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int nx=g[x][i];
		if(nx==fa) continue;
		if(vis[x]&&vis[nx]) merge(x,nx);
		check(nx,x);
	}
}
int dist[101][101];
void dfs(int st,int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int nx=g[x][i];
		if(nx==fa) continue;
		dist[st][nx]=dist[st][x]+1;
		dfs(st,nx,x);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dist[i][i]=0;
			dfs(i,i,0);
		}
		int ans=n;
		for(int S=0;S<(1<<n);S++){
			if(__builtin_popcount(S)!=k) continue;
			for(int i=1;i<=n;i++){
				if(S&(1<<(i-1))) vis[i]=1;
				else vis[i]=0;
			}
			init();
			check(1,0);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(vis[i]&&i==find(i)) cnt++;
			}
			if(cnt>2) continue;
			int mx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				int mn=n;
				for(int j=1;j<=n;j++){
					if(vis[j]) mn=min(mn,dist[i][j]);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}

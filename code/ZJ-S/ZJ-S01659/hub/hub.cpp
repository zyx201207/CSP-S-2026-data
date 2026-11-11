#include<bits/stdc++.h>

using namespace std;

const int N=1000+5,inf=1e9;
int c,t;
int n,k,ans=inf;
int a[N],dis[N][N],fa[N];
bool vis[N];
bool e[N][N];
vector<int> g[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void dfs(int st,int cnt){
	if(cnt==k){
		int ret=0;
		for(int i=1;i<=k;i++) fa[a[i]]=a[i];
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(i==j) continue;
				int x=a[i],y=a[j];
				if(e[x][y]){
					int fx=get(x),fy=get(y);
					if(fx==fy) continue;
					fa[fy]=fx;
				}
			}
		}
		int C=0;
		for(int i=1;i<=k;i++){
			int x=a[i];
			if(get(x)==x) C++;
		}
		if(C>2) return;
		for(int i=1;i<=n;i++){
			int x=i,res=inf;
			for(int j=1;j<=k;j++){
				int y=a[j];
				res=min(res,dis[x][y]);
			}
			ret=max(ret,res);
		}
		ans=min(ans,ret);
		return ;
	}
	if(st>n) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[st]=i;vis[i]=1;
		dfs(st+1,cnt+1);
		vis[i]=0;
	}
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dis[s][v]==inf){
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
}
void solve(){
	cin>>n>>k;ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
			e[i][j]=0;
		}
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u][v]=e[v][u]=1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int c,t,n,k,dist[N][22],deep[N],vis[N],ans,vs[N];
vector<int>E[N];
void dfs1(int x,int fa){
	dist[x][0]=fa;
	for(int j=1;j<=20;j++){
		dist[x][j]=dist[dist[x][j-1]][j-1];
	}
	for(auto now:E[x]){
		if(now==fa) continue;
		deep[now]=deep[x]+1;
		dfs1(now,x);
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int j=20;j>=0;j--){
		if(deep[dist[x][j]]>=deep[y]) x=dist[x][j];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(dist[x][i]==dist[y][i]) continue;
		x=dist[x][i];
		y=dist[y][i];
	}
	return dist[x][0];
}
void dfs2(int x){
	for(auto now:E[x]){
		if(vs[now]) continue;
		if(vis[now]){
			vs[now]=1;
			dfs2(now);
		}
	}
}
void dfs(int x,int num){
	if(x>n){
		int res=0;
		if(num!=0) return;
		int sum=0;
		memset(vs,0,sizeof(vs));
		for(int i=1;i<=n;i++){
			if(vis[i]&&!vs[i]){
				vs[i]=1;
				sum++;
				dfs2(i);
			}
		}
		if(sum>2) return;
		for(int i=1;i<=n;i++){
			int mi=1e9;
			for(int j=1;j<=n;j++){
				if(vis[j]) mi=min(deep[i]+deep[j]-2*deep[lca(i,j)],mi);
			}
			res=max(mi,res);
		}
		ans=min(ans,res);
		return;
	}
	vis[x]=1;
	dfs(x+1,num-1);
	vis[x]=0;
	dfs(x+1,num);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		ans=1e9;
		dfs1(1,0);
		dfs(1,k);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			E[i].clear();
			deep[i]=0;
			vis[i]=0;
			for(int j=0;j<=20;j++){
				dist[i][j]=0;
			}
		}
	}
	return 0;
} 

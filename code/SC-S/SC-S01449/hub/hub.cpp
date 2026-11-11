#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int c,t,n,k;
vector<int> G[N];
int a[N],vis[N],tot;
int dep[N];int fa[N];
void dfs1(int u,int f,int lst){
	fa[u]=f;dep[u]=dep[f]+1;
	if(f!=lst&&vis[u]) tot++;
	int nw = (vis[u]?u:lst);
	for(int v:G[u])if(v!=f)dfs1(v,u,nw);
}
int mi;
int dfs2(int u,int fa,int lst){
//	int val = lst,nw=(vis[u]?0:lst+1);
//	int minn = 1e18;
//	for(int v:G[u]){
//		if(v==fa)continue;
//		dfs2(v,u,nw);
//	}
	
	int nw = (vis[u]?u:lst);
	int val = dep[u]-dep[nw],minn=vis[u]?0:1e18;
//	cout<<"U:"<<u<<" "<<minn<<"\n";
	for(int v:G[u]){
		if(v==fa) continue;
//		cout<<"D:"<<dfs2(v,u,nw)+1<<"\n";
		minn=min(minn,dfs2(v,u,nw)+1);
	}
	mi = max(mi,min({val,minn}));
	return minn;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=fa[u];
	if(u==v) return u;
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}
bool used[N];
int lca[15][15];
int ans = 1e18;
void dfs(int cnt){
//	if(l<n-cnt+1)return ;
//	cout<<"C:"<<cnt<<" "<<l<<"\n";
	if(cnt==k+1){
//		cout<<"in\n";
//		cout<<a[1]<<" "<<a[2]<<"\n";
//		cout<<"A:"<<a[1]<<"\n";
		fill(vis+1,vis+n+1,0);tot=0;mi=0;
		for(int i=1;i<=k;++i)vis[a[i]]=1;
//		dep[1]=1,dep[0]=-1e18;
		dfs1(1,0,-1);
//		cout<<"in\n";
//		dfs2(1,0,0);ans=min(ans,mi);
		int mx = 0;
//		cout<<"A:"<<a[1]<<" "<<a[2]<<"\n";
//		if(a[1]==3&&a[2]==9&&a[3]==8){
//			cout<<"TTT:"<<tot<<"\n";
//			
//		}
		if(tot>2)return ;
		for(int i=1;i<=n;++i){
			if(vis[i]) continue;
			int val = 1e18;
			for(int j=1;j<=n;++j){
				if(vis[j]){
					val=min(val,dep[i]+dep[j]-2*dep[lca[i][j]]);
				}
//					cout<<i<<" "<<j<<" "<<LCA(i,j)<<'\n';
			}
//			cout<<"I:"<<i<<" "<<val<<"\n";
			mx=max(mx,val);
		}
//		if(!mx){
//			cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<"\n";
//		}
		ans=min(ans,mx);
		return ;
//		exit(0);
	}
	for(int i=n;i>=1;--i){
		if(used[i]) continue;
		a[cnt]=i;used[i]=1;dfs(cnt+1);used[i]=0;
//		if(i==1) cout<<"PPP:"<<cnt<<" "<<"\n";
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		G[u].push_back(v);G[v].push_back(u);
	}
	dfs1(1,0,-1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			lca[i][j]=LCA(i,j);
	}
	ans=1e18;dfs(1);cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
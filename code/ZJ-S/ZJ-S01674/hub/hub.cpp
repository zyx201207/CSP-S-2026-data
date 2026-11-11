#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,k,d[N],f[21][N],ans,to[N][N];
vector<int> u[N];
inline void dfs1(int x,int fa){
	d[x]=d[fa]+1,f[0][x]=fa;
	for(int i=1;i<=20;i++) f[i][x]=f[i-1][f[i-1][x]];
	for(int i=0;i<u[x].size();i++){
		int v=u[x][i];
		if(v==fa) continue;
		dfs1(v,x);
	}
}
inline int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(d[f[i][x]]>=d[y]) x=f[i][x];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	return f[0][x];
}
int b[N],vis[N],fa[N];
inline int zx(int x){
	if(fa[x]!=x) return fa[x]=zx(fa[x]);
	return x;
}
inline void dfs(int x,int y){
	if(x==k){
		int tot=k;
		for(int i=1;i<=k;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if(to[b[i]][b[j]]){
					int hhx=zx(i),hhy=zx(j);
					if(hhx==hhy) continue;
					fa[hhx]=hhy,tot--;
				}
			}
		}
		if(tot>2) return ;
//		for(int i=1;i<=k;i++) cout<<b[i]<<" ";
//		cout<<"\n";
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int minn=INT_MAX;
			for(int j=1;j<=k;j++){
				int la=lca(i,b[j]);
				if(la==i) minn=min(minn,d[b[j]]-d[la]);
				else if(la==b[j]) minn=min(minn,d[i]-d[la]);
				else minn=min(minn,d[b[j]]-d[la]+d[i]-d[la]);
			}
			maxx=max(maxx,minn);
		}
//		cout<<maxx<<"\n";
		ans=min(ans,maxx);
		return ;
	}
	for(int i=y;i<=n;i++){
		b[x+1]=i,vis[i]=1; dfs(x+1,i+1); vis[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--){
		cin>>n>>k; ans=INT_MAX;
		for(int i=1;i<=n;i++) u[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) to[i][j]=0;
		for(int i=1;i<n;i++){
			int x,y; cin>>x>>y; to[x][y]=1;
			u[x].push_back(y),u[y].push_back(x);
		}
		d[1]=0;
		dfs1(1,1);
		dfs(0,1);
		cout<<ans<<"\n";
	}	
	return 0;
}

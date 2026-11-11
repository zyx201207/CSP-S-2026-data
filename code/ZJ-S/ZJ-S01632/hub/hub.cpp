//#include<bits/stdc++.h>
//using namespace std;
//int tp,T,n,m,vis[1000005],ans,now;vector<int>q[1000005];
//int fa[1000005][20],dep[1000005];
//void dfs(int x,int f){
//	fa[x][0]=f,dep[x]=dep[f]+1;
//	for(auto v:q[x])if(v!=f)dfs(v,x);
//}
//void init(){
//	for(int j=1;j<20;j++){
//		for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
//	}
//}
//int lca(int x,int y){
//	if(dep[x]<dep[y])swap(x,y);
//	for(int i=19;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
//	if(x==y)return x;
//	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
//	return fa[x][0];
//}
//int dis(int x,int y){
//	return dep[x]+dep[y]-2*dep[lca(x,y)];
//}
//void clear(){
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<20;j++)fa[i][j]=0;
//		q[i].clear(),vis[i]=dep[i]=0;
//	}
//}
//int f[1000005],g[1000005],h1[1000005],h2[1000005];
//void dfs1(int x,int fa){
//	f[x]=0,g[x]=0,h1[x]=0,h2[x]=0;
//	for(auto v:q[x])if(v!=fa){
//		dfs1(v,x);h1[x]=max(h1[x],h1[v]);
//		if(f[v]+1>f[x])g[x]=f[x],f[x]=f[v]+1;
//		else if(f[v]+1>g[x])g[x]=f[v]+1;
//	}
//	h1[x]=max(h1[x],f[x]+g[x]);
//}
//void dfs2(int x,int fa,int d,int D=0){
//	d++;multiset<int>s;s.insert(d);
//	ans=min(ans,max((h1[x]+1)/2,(D+1)/2));
//	for(auto v:q[x])if(v!=fa)s.insert(f[v]+1);
//	for(auto v:q[x])if(v!=fa){
//		int d2=D;
//		s.erase(s.find(f[v]+1));
//		if(s.size()>1){
//			d2=max(d2,(*(--s.end()))+(*(--(--s.end()))));
//		}
//		else if(s.size()==1)d2=max(d2,*(--s.end()));
//		if(f[v]+1==f[x])dfs2(v,x,max(d,g[x]),d2);
//		else dfs2(v,x,max(d,f[x]),d2);
//	}
//}
//void solve(){
//	cin>>n>>m;for(int i=1,u,v;i<n;i++)cin>>u>>v,q[u].emplace_back(v),q[v].emplace_back(u);
//	ans=n;dfs(1,0);init();
//	if(m==2){
//		dfs1(1,0);dfs2(1,0,-1);
//		cout<<ans<<'\n';
//		return clear();
//	}
//	for(int s=0;s<(1<<n);s++){
//		int c=0;for(int i=0;i<n;i++)vis[i+1]=((s>>i)&1),c+=vis[i+1];
//		if(c!=m)continue;
//		int cnt=0;
//		for(int i=1;i<=n;i++)if(vis[i]){
//			for(auto j:q[i])if(vis[j])cnt++;
//		}
//		cnt/=2;
//		if(m-cnt!=2)continue;
//		now=0;
//		for(int i=1;i<=n;i++)if(!vis[i]){
//			int d=n;
//			for(int j=1;j<=n;j++)if(vis[j]){
//				d=min(d,dis(i,j));
//			}
//			now=max(now,d);
//		}
//		ans=min(ans,now);
//	}
//	cout<<ans<<'\n';
//	clear();
//}
//signed main(){
//	freopen("hub4.in","r",stdin);
//	//freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>tp>>T;while(T--)solve();
//}
#include<bits/stdc++.h>
using namespace std;
int tp,T,n,m,vis[1000005],ans,now;vector<int>q[1000005];
int fa[1000005][20],dep[1000005];
void dfs(int x,int f){
	fa[x][0]=f,dep[x]=dep[f]+1;
	for(auto v:q[x])if(v!=f)dfs(v,x);
}
void init(){
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void clear(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++)fa[i][j]=0;
		q[i].clear(),vis[i]=dep[i]=0;
	}
}
void solve(){
	cin>>n>>m;for(int i=1,u,v;i<n;i++)cin>>u>>v,q[u].emplace_back(v),q[v].emplace_back(u);
	ans=n;dfs(1,0);init();
	for(int s=0;s<(1<<n);s++){
		int c=0;for(int i=0;i<n;i++)vis[i+1]=((s>>i)&1),c+=vis[i+1];
		if(c!=m)continue;
		int cnt=0;
		for(int i=1;i<=n;i++)if(vis[i]){
			for(auto j:q[i])if(vis[j])cnt++;
		}
		cnt/=2;
		if(m-cnt!=2)continue;
		now=0;
		for(int i=1;i<=n;i++)if(!vis[i]){
			int d=n;
			for(int j=1;j<=n;j++)if(vis[j]){
				d=min(d,dis(i,j));
			}
			now=max(now,d);
		}
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
	clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>tp>>T;while(T--)solve();
}
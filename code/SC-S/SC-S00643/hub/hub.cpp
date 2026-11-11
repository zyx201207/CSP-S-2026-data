#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
const int maxn=1e3+20;
int dis[maxn][maxn],a[maxn],n,fw,T,k,fa[maxn],vis[maxn],ans;
vector<int> e[maxn];
int find(int x){if(x==fa[x]) return x;return fa[x]=find(fa[x]);}
inline void merge(int x,int y){x=find(x),y=find(y);if(x!=y) fa[x]=y;}
void dfs(int u,int fa,int rt){
	for(int v:e[u]){
		if(v==fa) continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs(v,u,rt);
	}
}
inline void getans(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		for(int v:e[a[i]]) if(vis[v]) merge(i,v);
	}
	int cnt=0;
	for(int i=1;i<=k;i++) if(fa[a[i]]==a[i]) cnt++;
	if(cnt>2) return;
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int now=1e9;
		for(int j=1;j<=k;j++) now=min(now,dis[i][a[j]]);
		res=max(now,res);
	}
	ans=min(ans,res);
}
void gogo(int now,int cnt){
	if(now>n){
		if(cnt==k) getans();
		return;
	}
	gogo(now+1,cnt);
	a[cnt+1]=now,vis[now]=1;
	gogo(now+1,cnt+1);
	vis[now]=0;
}
inline void solve(){
	n=read(),k=read();ans=1e9;
	int u,v;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;i++) dfs(i,0,i);
	gogo(1,0);
	cout<<ans<<'\n';
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fw=read(),T=read();
	while(T--) solve();
	return 0;
}

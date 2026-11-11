#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll=long long;using db=double;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int N=1e6+10;
int n,k,dep[N],f[N][25];
vector<int> g[N];
inline void dfs(int u, int fa){
	dep[u]=dep[fa]+1,f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
inline int LCA(int u, int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(f[u][i]^f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
inline int dis(int u, int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int cnt,vis[N];
inline void dfs2(int u, int S, int fa){
	vis[u]=1;
	for(int v:g[u]){
		if(v==fa) continue;
		if(S&(1<<(v-1))&&!vis[v]){
			cnt--;
			dfs2(v,S,u);
		}
	}
}
inline bool check(int S){
	cnt=k;
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=n;i++) if(S&(1<<(i-1))&&!vis[i]) dfs2(i,S,0);
	return cnt==2;
}
inline int calc(int S){
	int res=0;
	for(int i=1;i<=n;i++){
		int mi=INF;
		for(int j=1;j<=n;j++){
			if(S&(1<<(j-1))) mi=min(mi,dis(i,j));
		}
		res=max(res,mi);
	}
	return res;
}
inline void solve(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) g[i].clear();
	for(int u,v,i=1;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	if(n<=10){
		int ans=INF;
		for(int S=0;S<(1<<n);S++){
			int num=__builtin_popcountll(S);
			if(num!=k||!check(S)) continue;
			ans=min(ans,calc(S));
		}
		write(ans),puts("");
	}
	else{
		write((n-1)/2),puts("");
	}
	for(int i=1;i<=n;i++){
		dep[i]=0;
		for(int j=0;j<=20;j++) f[i][j]=0;
	}
//	write()
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--) solve();
	return 0;
}
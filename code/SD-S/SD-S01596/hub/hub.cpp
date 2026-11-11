#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
int C,T;
namespace Subtask1{
	const int N=35;
	struct Edge{
		int head[N],idx,maxn;
		struct edge{
			int nxt,to;
		}e[N<<1];
		void add(int u,int v){
			e[++idx]=(edge){head[u],v};
			head[u]=idx;maxn=max({maxn,u,v});
		}
		void clear(){
			for(int i=1;i<=idx;i++) e[i].nxt=e[i].to=0;
			for(int i=1;i<=maxn;i++) head[i]=0;maxn=idx=0;
		}
	}G;
	int n,k,dis[N][N],pre[N][N],suf[N][N];
	void dfs(int u,int fa,int *dep){
		for(int i=G.head[u];i;i=G.e[i].nxt){
			int v=G.e[i].to;
			if(v==fa) continue;
			dep[v]=dep[u]+1;
			dfs(v,u,dep);
		}
	}
	int vis[N],a[N];
	void dfs(int u){
		vis[u]=1;
		for(int i=G.head[u];i;i=G.e[i].nxt){
			int v=G.e[i].to;
			if(vis[v]||!a[v]) continue;
			dfs(v);
		}
	}
	void Solve(){
		G.clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G.add(u,v);G.add(v,u);
		}
		for(int i=1;i<=n;i++) dfs(i,0,dis[i]);
		int U=(1<<n)-1,ans=INF;
		for(int S=0;S<=U;S++){
			if(__builtin_popcount(S)!=k) continue;
			for(int i=0;i<n;i++) a[i+1]=(S>>i)&1,vis[i+1]=0;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]&&!vis[i]){
					cnt++;
					dfs(i);
				}
			}
			if(cnt>2) continue;
			int now=0;
			for(int i=1;i<=n;i++){
				int val=INF;
				for(int j=1;j<=n;j++)
					if(a[j]) val=min(val,dis[i][j]);
				now=max(now,val);
			}
			ans=min(ans,now);
		}
		cout<<ans<<'\n';
	}
	void solve(){
		while(T--){
			Solve();
		}
	}
};
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	if(C<=3){Subtask1::solve();return 0;}
//	if(C==7){Subtask2::solve();return 0;}
	return 0;
}

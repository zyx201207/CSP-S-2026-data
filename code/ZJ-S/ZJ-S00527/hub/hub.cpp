#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double 
#define pb push_back
#define eb emplace_back
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memset(x,y,sizeof(x))
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e5+20,M=1000+20,P=20;
const ll INF=1e18,mod=998244353;
namespace Sol0{
	int n,k;
	vector<int> to[P];
	bool vis[P];
	int dis[P],dep[P];
	bool check(){
		int num=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) num+=2;
		}
		for(int i=1;i<=n;i++){
			for(int v:to[i]){
				if(vis[i] && vis[v]) num--;
			}
		}
		return num==4;
	}
	void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		for(int v:to[u]){
			if(v==fa) continue;
			dfs(v,u);
		}
	}
	void init(){
		for(int i=1;i<=n;i++){
			to[i].clear();
		}
	}
	void solve(){
		cin>>n>>k;
		init();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			to[u].pb(v);
			to[v].pb(u);
		}
		int ans=mod;
		for(int t=0;t<(1<<n);t++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if((t>>(i-1))&1) vis[i]=1,cnt++;
				else vis[i]=0;
			}
			if(cnt!=k) continue;
			if(!check()) continue;
			// cerr<<"**\n";
			for(int i=1;i<=n;i++) dis[i]=mod;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					dfs(i,0);
					for(int j=1;j<=n;j++) dis[j]=min(dis[j],dep[j]);
				}
			}
			int tp=0;
			for(int i=1;i<=n;i++) tp=max(tp,dis[i]);
			ans=min(ans,tp);
		}
		cout<<ans-1<<"\n";
	}
	void sol0(){
		int T=1;cin>>T;
		while(T--) solve();
	}
}
namespace Sol7{
	int n,k;
	vector<int> to[M];
	bool vis[M];
	int dis[M],dep[M];
	bool check(){
		int num=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) num+=2;
		}
		for(int i=1;i<=n;i++){
			for(int v:to[i]){
				if(vis[i] && vis[v]) num--;
			}
		}
		return num==4;
	}
	void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		for(int v:to[u]){
			if(v==fa) continue;
			dfs(v,u);
		}
	}
	void init(){
		for(int i=1;i<=n;i++){
			to[i].clear();
		}
	}
	void solve(){
		cin>>n>>k;
		init();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			to[u].pb(v);
			to[v].pb(u);
		}
		int ans=mod;
		for(int ti=1;ti<=n;ti++){
			for(int tj=1;tj<=n;tj++){
				vis[ti]=1,vis[tj]=1;
				if(!check()){
					vis[ti]=vis[tj]=0;
					continue;
				}
				for(int i=1;i<=n;i++) dis[i]=mod;
				dfs(ti,0);
				for(int i=1;i<=n;i++) dis[i]=min(dis[i],dep[i]);
				dfs(tj,0);
				for(int i=1;i<=n;i++) dis[i]=min(dis[i],dep[i]);				
				int tp=0;
				for(int i=1;i<=n;i++) tp=max(tp,dis[i]);
				ans=min(ans,tp);
				vis[ti]=0,vis[tj]=0;
			}				
		}
		cout<<ans-1<<"\n";
	}
	void sol7(){
		int T=1;cin>>T;
		while(T--) solve();
	}
}
// namespace Sol1{
// 	int n,k;
// 	int siz[N],g[N],h[N];
// 	int f[M][M][2],tmp[M][2];
// 	vector<int> to[M];
// 	void dfs0(int u,int fa){
// 		for(int v:to[u]){
// 			if(v==fa) continue;
// 			dfs0(v,u);
// 		}
// 	}
// 	void dfs(int u,int fa){
// 		for(int i=1;i<=k;i++){
// 			MS(f[u][i],0x3f);
// 		}
// 		f[u][0][0]=0;
// 		siz[u]=0;
// 		for(int v:to[u]){
// 			if(v==fa) continue;
// 			dfs(v,u);
// 			for(int i=0;i<=min(siz[u],k);i++){
// 				MC(tmp[i],f[u][i]);
// 				MS(f[u][i],0x3f);
// 			}
// 			for(int i=0;i<=siz[u];i++){
// 				for(int j=0;j<=siz[v];j++){
					
// 				}
// 			}
// 		}
// 	}
// 	void solve(){
// 		cin>>n>>k;
// 		for(int i=1,u,v;i<n;i++){
// 			cin>>u>>v;
// 			to[u].pb(v);
// 			to[v].pb(u);
// 		}
// 		dfs(1,0);
// 		cout<<min(f[1][k][2][0],f[1][k][2][1])<<"\n";
// 	}
// 	void sol1(){
// 		int T=1;cin>>T;
// 		while(T--) solve();
// 	}
// }
namespace H_H{
	int main(){
		int c;cin>>c;
		if(c<=3) Sol0::sol0();
		if(c==7) Sol7::sol7();
		// if(c<=10) Sol1::sol1();
		// if(c==11 || c==12) Sol2::sol2();
		// if(c==13 || c==14) Sol3::sol3();
		// if(c==15) Sol4::sol4();
		return 0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;H_H::main();
	return 0;
}
//g++ 1.cpp -o 1 -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow "-Wl,--stack=1234567890"
#include <bits/stdc++.h>

#define fr for
//#define int long long

using namespace std;

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

const int N=2e5+7;vector<int>G[N];

namespace hld{
	int d[N],f[N],s[N],top[N],hson[N];

	void dfs1(int u,int fa){
		f[u]=fa;s[u]=1;d[u]=d[fa]+1;
		fr(auto v:G[u]){
			if(v==fa)continue;
			dfs1(v,u);
			s[u]+=s[v];
			if(!hson[u]||s[v]>s[hson[u]])hson[u]=v;
		}
	}
	
	void dfs2(int u,int t){
		top[u]=t;
		if(hson[u])dfs2(hson[u],t);
		fr(auto v:G[u]){
			if(v==f[u]||v==hson[u])continue;
			dfs2(v,v);
		}
	} 
	
	int lca(int u,int v){
		while(top[u]!=top[v]){
			if(d[top[u]]<d[top[v]])swap(u,v);
			u=f[top[u]];
		}
		return d[u]<d[v]?u:v;
	}
	
	int dis(int u,int v){
		return d[u]+d[v]-2*d[lca(u,v)];
	}
}
using hld::dis;
int vis[N];
namespace solve1{
	int fa[N];
	int dsu(int u){
		return fa[u]==u?u:fa[u]=dsu(fa[u]);
	}
	void solve(){
		int n=read(),k=read();
		fr(int i=1;i<=n;i++){
			G[i].clear();
			hld::hson[i]=0;
		}
		fr(int i=1;i<n;i++){
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		hld::dfs1(1,0);
		hld::dfs2(1,1);
		int ans=1e9+7;
		fr(int mask=0;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)!=k)continue;
			vector<int>cand;
//			fr(int i=1;i<=n;i++)vis[i]=0;
fr(int i=1;i<=n;i++)vis[i]=0;
			fr(int i=0;i<n;i++){
				if((mask>>i)&1){
					cand.push_back(i+1);
//					if(mask==322)cerr<<"!!!i+i"<<i+1<<"\n";
					vis[i+1]=1;;
				}
			}
			fr(int i=1;i<=n;i++)fa[i]=i;
//			if(mask==322){
//				fr(int i=1;i<=n;i++)cerr<<i<<"--"<<vis[i]<<"\n";
//			}
			
			fr(auto u:cand){
				fr(auto v:G[u]){
					
					if(vis[v])fa[dsu(u)]=dsu(v);
				}
			}
			int cnt=0;
			fr(int i=1;i<=n;i++)if(vis[i])cnt+=(i==dsu(i));
//			if(mask==322)cerr<<cnt<<"!!!\n";
			if(cnt>2)continue;
			int res=0;
			fr(int i=1;i<=n;i++){
				int mn=1e9+7;
				fr(auto j:cand){
					mn=min(mn,dis(i,j));
				}
				res=max(res,mn);
			}
//			cerr<<res<<"|"<<mask<<'\n'; 
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _=read(),T=read();
	while(T--){
		solve1::solve();
	}
	return 0;
}
/*

15pts

估分：100+100+24+15=239

有 7 吗，不会今年一等线三百吧

再去拼点暴力 

拼不出来/ll，比去年还差，可能是最后一场CSP了 

By C_0_a4S,Luogu_uid=1424067

都 2026 年了，我怎么还在考 CSP？
            ###################
         ############\\############
       ##############\\##############
      ################################
     #######\\\\\\\\\\\\\\\\\\\\#######
    ####################################
    #############\\\\\\\\\##############
    #############\#######\##############
    #############\\\\\\\\\##############
    ####################################
     #######\\\\\\\\\\\\\\\\\\\\#######
      ######\##################\######
        ###########\\\\\\###########
          ########\######\##\#####
            ######\######\\\\###
             #################
 Oct31==Dec25?

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/


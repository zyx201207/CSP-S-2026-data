#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
bool M_S;
namespace cjr2010{
	namespace SUB1{
		const int N=15;
		int n,m;
		vector<int> e[N];
		array<int,2> E[N];
		int fa[N];
		int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
		int dis[N];queue<int> q;
		void MAIN1(){
			cin>>n>>m;
			For(i,1,n-1){
				int u,v;cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
				E[i]={u,v};
			}
			int ans=inf;
			For(s,0,(1<<n)-1){
				if(__builtin_popcount(s)==m){
					#define chk(x) (s>>(x-1)&1)
					For(i,1,n){
						if(chk(i)) fa[i]=i;
						else fa[i]=0;
					}
					For(i,1,n-1){
						auto [u,v]=E[i];
						if(chk(u)&&chk(v)) fa[find(u)]=find(v);
					}
					int cnt=0;
					For(i,1,n) if(chk(i)) cnt+=find(i)==i;
					if(cnt>2) continue;
					For(i,1,n){
						if(chk(i)) dis[i]=0,q.push(i);
						else dis[i]=inf;
					}
					while(!q.empty()){
						int u=q.front();q.pop();
						for(int v:e[u]){
							if(dis[v]==inf){
								dis[v]=dis[u]+1;
								q.push(v);
							}
						}
					}
					int res=0;
					For(i,1,n) res=max(res,dis[i]);
					ans=min(ans,res);
				}
			}
			cout<<ans<<"\n";
		}
		void _MAIN1(){
			For(i,1,n) e[i].clear();
		}
		int T;
		void MAIN(){
			cin>>T;
			For(_,1,T) MAIN1(),_MAIN1();
		}
	}
	int SUB;
	void MAIN(){
		cin>>SUB;
		if(SUB<=3){SUB1::MAIN();return ;}
	}
}
bool M_T;
signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	double T_S=clock();cjr2010::MAIN();double T_T=clock();
	cerr<<(T_T-T_S)/CLOCKS_PER_SEC<<"s\n";
	cerr<<(&M_S-&M_T)/1048576.0<<"MiB\n";
	return 0;
}
/*
hub
g++ 4.cpp -o 4 -O2 -std=c++14 -static && .\4
*/
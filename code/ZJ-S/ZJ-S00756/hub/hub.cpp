#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<random>
//#include<ctime>
using namespace std;
bool beginmem;
//clock_t begintim;
#define N 1000005
namespace ElEp{
	void __init__(){
		return ;
	}
	int fa[N],dis[N],n,k;
	vector<int> edge[N];
	int find(int x){
		return fa[x] == x?x:fa[x] = find(fa[x]);
	}
	void merge(int x,int y){
		if((x=find(x))==(y=find(y))) return ;
		fa[y] = x;
	}
	void dfs(int x,int fa){
		for(int i:edge[x]){
			if(i==fa) continue;
			dis[i] = min(dis[i],dis[x]+1);
			dfs(i,x);
		}
		return ;
	}
	set<int> st;
	void work(){
		cin>>n>>k;
		for(int i=1;i<=n;++i) edge[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			edge[u].emplace_back(v);
			edge[v].emplace_back(u);
		}
		int ans = n;
		for(int mask=0;mask<(1<<n);++mask){
			if(__builtin_popcount(mask)!=k) continue;
			st.clear();
			for(int i=1;i<=n;++i) fa[i] = i,dis[i] = 1e9;
			for(int i=1;i<=n;++i){
				if(mask>>(i-1)&1){
					for(int v:edge[i]){
						if(mask>>(v-1)&1){
							merge(i,v);
						}
					}
				}
			}
			for(int i=1;i<=n;++i){
				if(mask>>(i-1)&1){
					dis[i] = 0;
					dfs(i,0);
					st.insert(find(i));
				}
			}
			if(st.size()>2) continue;
			int res = 0;
			for(int i=1;i<=n;++i) res = max(res,dis[i]);
			ans = min(ans,res);
		}
		cout<<ans<<'\n';
		return ;
	}
}
bool endmem;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(5);
	cerr<<fixed<<setprecision(5);
	int T = 1,c;
	cin>>c>>T;
	ElEp::__init__();
	while(T--) ElEp::work();
//	cerr<<"Time used: "<<(clock()-begintim)<<" ms.\n";
//	cerr<<"Memory used: "<<abs(&endmem-&beginmem)/1048576.<<" MB.\n";
	return 0;
}
/*
author: Ethereal_loss & Eternal_poem
created: 2026/10/31 17:42:35
exp:
先考虑k=2，相当于放置两个点，求到这两个点的最小的距离
wqs二分消掉k的限制，但是还有连通块数量的限制

*/


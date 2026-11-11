#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
namespace wangruofan{
	using ll=long long;
	constexpr int N=2e6+9;
	int c,t,n,k,ans,d[11],dist[N];
	bool vst[11];
	std::vector<int> es[N];
	void solve2(){
		int mx=0,id;
		auto dfs_=[&](int x,int fa,auto &&self)->void{
			dist[x]=dist[fa]+1;
			if(dist[x]>mx){
				mx=dist[x];
				id=x;
			}
			for(int y:es[x]){
				if(y!=fa) self(y,x,self);
			}
		};
		dfs_(1,0,dfs_);
		mx=0;
		dfs_(id,0,dfs_);
		printf("%d\n",(mx+1)/4);
	}
	void solve(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			es[i].clear();
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			es[u].emplace_back(v);
			es[v].emplace_back(u);
		}
//		if(k==2){
//			solve2();
//			return;
//		}
		ans=1e9;
		auto _dfs=[](int x,int fa,int S,auto &&self)->void{
			for(auto y:es[x]){
				if(y==fa||!(S>>(y-1)&1)) continue;
				vst[y]=1;
				self(y,x,S,self);
			}
		};
		for(int S=0;S<(1<<n);++S){
			if(__builtin_popcount(S)!=k) continue;
			memset(vst,0,sizeof vst);
			int C=0;
			for(int i=1;i<=n;++i){
				if(((S>>(i-1))&1)&&!vst[i]){
					vst[i]=1;
					_dfs(i,0,S,_dfs);
					++C;
					if(C>2)
						break;
				}
			}
			if(C>2) continue;
			memset(d,0,sizeof d);
			std::queue<int> q;
			for(int i=1;i<=n;++i)
				if(S>>(i-1)&1) q.emplace(i);
			int nw=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:es[u]){
					if(!vst[v]){
						vst[v]=1;
						d[v]=d[u]+1;
						nw=std::max(nw,d[v]);
						q.emplace(v);
					}
				}
			}
			ans=std::min(ans,nw);
		}
		printf("%d\n",ans);
	}
	void main(){
		scanf("%d%d",&c,&t);
		while(t--)
			solve();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	wangruofan::main();
	return 0;
}

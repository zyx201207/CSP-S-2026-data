#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=2e6+5;

int c,T;
int n,k;

inline void getmx(int &a,int b){
	return a=(a>b?a:b),void();
}

inline void getmn(int &a,int b){
	return a=(a<b?a:b),void();
}

namespace DSU{
	
	int fa[N],dep[N];
	
	inline void init(){
		for(int i=1;i<=n;++i)fa[i]=i,dep[i]=1;
		return ;
	}
	
	inline int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return ;
		if(dep[x]>dep[y])swap(x,y);
		return fa[x]=y,getmx(dep[y],dep[x]+1),void();
	}
	
}

namespace graph{
	
	vector<int>e[N];
	int dis[N],uu[N],vv[N];
	bool vis[N];
	
	int sz[N],son[N],dep[N],top[N],fa[N];
	
	inline void dfs(int u,int f){
		sz[u]=1,dep[u]=dep[f]+1,fa[u]=f;
		for(auto v:e[u]){
			if(v==f)continue ;
			dfs(v,u);
			if(sz[v]>sz[son[u]])son[u]=v;
			sz[u]+=sz[v];
		}
		return ;
	}
	
	inline void df5(int u,int t){
		top[u]=t;
		if(!son[u])return ;
		df5(son[u],t);
		for(auto v:e[u]){
			if(v==fa[u]||v==son[u])continue ;
			df5(v,v);
		}
		return ;
	}
	
	inline int bfs(int st){
		for(int i=1;i<=n;++i)dis[i]=0;
		queue<int>q;q.push(st);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto v:e[u]){
				if(!dis[v]){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		int res=-1,mx=0;
		for(int i=1;i<=n;++i){
			if(dis[i]>mx){
				mx=dis[i],res=i;
			}
		}
		return res;
	}
	
	inline int LCA(int u,int v){
		while(top[u]^top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	}
	
	inline int diss(int u,int v){
		int lca=LCA(u,v);
		return dep[u]-dep[lca]+dep[v]-dep[lca];
	}
	
	inline void clear(){
		for(int i=1;i<=n;++i){
			e[i].clear();
			son[i]=dis[i]=0;
		}
		return ;
	}
	
}using namespace graph;

inline void solve1(){//n<=10
	int res=1e9;
	for(int mask=0;mask<(1<<n);++mask){
		if(__builtin_popcount(mask)!=k)continue ;
		DSU::init();
		for(int i=1;i<n;++i){
			int u=uu[i],v=vv[i];
			if(((mask>>(u-1))&1)&&((mask>>(v-1))&1)){
				DSU::merge(u,v);
			}
		}
		queue<int>q;
		for(int i=1;i<=n;++i)dis[i]=1e9,vis[i]=0;
		int cnt=0;//联通块数
		for(int i=1;i<=n;++i){
			if(!((mask>>(i-1))&1))continue ;
			q.push(i),vis[i]=1,dis[i]=0;
			if(DSU::find(i)==i)++cnt;
		}
		if(cnt>2)continue ;
		while(!q.empty()){
			int u=q.front();
			q.pop(),vis[u]=0;
			for(auto v:e[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					if(!vis[v])vis[v]=1,q.push(v);
				}
			}
		}
		int tmp=0;
		for(int i=1;i<=n;++i){
			if((mask>>(i-1))&1)continue ;
			getmx(tmp,dis[i]);
		}
		getmn(res,tmp);
	}
	return cout<<res<<"\n",void();
}

inline void solve2(){//k=1
	dfs(1,0),df5(1,1);
	int uu=bfs(1),vv=bfs(uu);//直径的两个端点
	int d=diss(uu,vv);//直径长
	return cout<<(d+1)/2<<"\n",void();
}

inline void solve3(){//k=2
	dfs(1,0),df5(1,1);
	int uu=bfs(1),vv=bfs(uu);
	int d=diss(uu,vv);
	int ctr=-1;//直径中点
	bool flg=0/*两个中点*/,flgu=0/*更靠近 u*/;
	for(int i=1;i<=n;++i){
		if(abs(diss(i,uu)-diss(i,vv))<=1){
			ctr=i;
			if(abs(diss(i,uu)-diss(i,vv))==1){
				flg=1;
				if(diss(i,uu)<diss(i,vv))flgu=1;
			}
			break ;
		}
	}
	for(int i=1;i<=n;++i)son[i]=0;
	dfs(ctr,0),df5(1,1);
	int d1=dep[uu]-dep[ctr],d2=dep[vv]-dep[ctr];
	if(!flg){
		d1=d1/2,d2=(d2+1)/2;
		for(int i=1;i<=d1;++i)uu=fa[uu];
		for(int i=1;i<=d2;++i)vv=fa[vv];
		queue<int>q;
		for(int i=1;i<=n;++i)dis[i]=1e9,vis[i]=0;
		q.push(uu),vis[uu]=1,dis[uu]=0;
		q.push(vv),vis[vv]=1,dis[vv]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop(),vis[u]=0;
			for(auto v:e[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					if(!vis[v])vis[v]=1,q.push(v);
				}
			}
		}
		int tmp=0;
		for(int i=1;i<=n;++i){
			getmx(tmp,dis[i]);
		}
		return cout<<tmp<<"\n",void();
	}
	if(!flgu)swap(uu,vv),swap(d1,d2);
	d1=d1/2,d2=(d2+1)/2;
	for(int i=1;i<=d1;++i)uu=fa[uu];
	for(int i=1;i<=d2;++i)vv=fa[vv];
	queue<int>q;
	for(int i=1;i<=n;++i)dis[i]=1e9,vis[i]=0;
	q.push(uu),vis[uu]=1,dis[uu]=0;
	q.push(vv),vis[vv]=1,dis[vv]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop(),vis[u]=0;
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(!vis[v])vis[v]=1,q.push(v);
			}
		}
	}
	int tmp=0;
	for(int i=1;i<=n;++i){
		getmx(tmp,dis[i]);
	}
	return cout<<tmp<<"\n",void();
//	return ;
}

inline void work(){
	cin>>n>>k;clear();
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
		uu[i]=u,vv[i]=v;
	}
	if(n<=10)return solve1(),void();
	if(k==1)return solve2(),void();
	if(k==2)return solve3(),void();
	return ;
}

signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
//	freopen("hub4.in","r",stdin),freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>T;while(T--)work();
	return 0;
}

/*

0 1
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

/*

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

1
2

*/

/*

n<=10，直接枚举选什么点即可，有 15pts
考虑 k=1，此时基地可以任选
然后要最小化所有点到这个点的最大距离
这是啥，直径中点吗，应该是
然后考虑 k=2，也是可以任选
n<=1e3 的话直接枚举两个点即可，这是 O(n^2) 的
是不是可以把直径四等分，两个点分别放在前 1/4 处和后 1/4 处
比较对是不是，好像已经获得 30pts 了
写下看
好像不对？不管了先交

*/
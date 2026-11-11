#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
const int N=1e3+10;
int c,t,n,k,u,v;
struct Tree{
	vector<int>g[N];
	void init(){
		for(int i=1;i<=n;++i){
			g[i].clear();
		}
	}
	void add(int u,int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int d[N][N];
	bitset<N>vis;
	void dfs(int x){
		vis[(unsigned long long)x]=1;
		int l=g[x].size();
		for(int i=0;i<l;++i){
			int j=g[x][(unsigned long long)i];
			if(!vis[(unsigned long long)j]){
				dfs(j);
			}
		}
	}
	void dfs1(int x,int st,int fa){
		int l=g[x].size();
		for(int i=0;i<l;++i){
			int j=g[x][(unsigned long long)i];
			if(j!=fa){
				d[st][j]=d[st][x]+1;
				dfs1(j,st,x);
			}
		}
	}
	bool check(int x){
		int scc=0;
		for(int i=0;i<n;++i){
			if((x>>i)&1){
				if(!vis[(unsigned long long)i+1]){
					if(scc==2){
						return false;
					}
					++scc;
					dfs(i+1);
				}
			}
		}
		return scc<=2;
	} 
}T;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	if(c<=3){
		for(int _=1;_<=t;++_){
			n=read();
			k=read();
			T.init();
			for(int i=1;i<n;++i){
				u=read();
				v=read();
				T.add(u,v);
			}
			for(int i=1;i<=n;++i){
				T.d[i][i]=0;
				T.dfs1(i,i,0);
			}
			int ans=0x3f3f3f3f;
			for(int msk=0;msk<(1<<n);++msk){
				T.vis.reset();
				if(__builtin_popcount((unsigned int)msk)==k&&T.check(msk)){
					int maxx=-0x3f3f3f3f;
					for(int j=1;j<=n;++j){
						int minn=0x3f3f3f3f;
						for(int i=0;i<n;++i){
							if((msk>>i)&1){
								minn=min(minn,T.d[j][i+1]);
							}
						}
						maxx=max(maxx,minn);
					}
					ans=min(ans,maxx);
				}
			}
			printf("%d\n",ans);
		}	
	}
	return 0;
}

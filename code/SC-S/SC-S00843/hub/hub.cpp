#include<bits/stdc++.h>
using namespace std;
int const N=1e6+1,inf=0x3f3f3f3f;
struct DSU{
	int fat[N];
	void init(int len){
		for(int i=1;i<=len;++i){
			fat[i]=i;
		}
	}
	int find(int x){
		if(fat[x]==x){
			return x;
		}
		return fat[x]=find(fat[x]);
	}
	void unite(int x,int y){
		fat[find(x)]=find(y);
	}
};
DSU dsu;
vector<int> g[N];
int ST[N][20];
int lg[N],fat[N],dep[N],dfn[N],pos[N];
int c,T,n,K,x,y,ans,ord;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void dfs(int u,int fa){
	dfn[++ord]=u;
	pos[u]=ord;
	fat[u]=fa;
	dep[u]=dep[fa]+1;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
}
int _min(int x,int y){
	if(dep[x]<dep[y]){
		return x;
	}
	return y;
}
int lca(int x,int y){
	if(x==y){
		return x;
	}
	if(pos[x]>pos[y]){
		swap(x,y);
	}
	int d=lg[pos[y]-pos[x]];
	return fat[_min(ST[pos[x]+1][d],ST[pos[y]-(1<<d)+1][d])];
}
int calc_dis(int x,int y){
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
bool judge(int state){
	dsu.init(n);
	for(int i=1;i<=n;++i){
		if(!(state&(1<<i-1))){
			continue;
		}
		for(int j=0;j<g[i].size();++j){
			int v=g[i][j];
			if(state&(1<<v-1)){
				dsu.unite(i,v);
			}
		}
	}
	int lst=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(state&(1<<i-1)){
			cnt+=(dsu.find(i)!=lst);
			lst=dsu.fat[i];
		}
	}
	return cnt<=2;
}
int calc(int state){
	int res=0;
	for(int i=1;i<=n;++i){
		if(state&(1<<i-1)){
			continue;
		}
		int mi=n;
		for(int j=1;j<=n;++j){
			if(state&(1<<j-1)){
				mi=min(mi,calc_dis(i,j));
			}
		}
		res=max(res,mi);
	}
	return res;
}
void prep(){
	for(int i=1;i<=n;++i){
		g[i].clear();
		g[i].shrink_to_fit();
	}
}
void solve(){
	if(c<=3){
		ord=0;
		dfs(1,0);
		for(int i=1;i<=n;++i){
			ST[i][0]=dfn[i];
		}
		for(int j=1;(1<<j)<=n;++j){
			for(int i=1;i+(1<<j)-1<=n;++i){
				ST[i][j]=_min(ST[i][j-1],ST[i+(1<<j-1)][j-1]);
			}
		}
		ans=inf;
		for(int state=0;state<(1<<n);++state){
			if(__builtin_popcount(state)!=K){
				continue;
			}
			if(!judge(state)){
				continue;
			}
			ans=min(ans,calc(state));
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	c=read();
	T=read();
	while(T--){
		prep();
		n=read();
		K=read();
		for(int i=0;i<n-1;++i){
			x=read();
			y=read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		solve();
		print(ans);
		putchar('\n');
	}
	return 0;
}
/*

Input #1:

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

Output #1:

1
2

*/
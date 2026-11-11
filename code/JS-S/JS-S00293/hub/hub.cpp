#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10,MAXK=2e6+10,MAXN1=5010;
int C,T;
int N,K;
int perm[MAXK];
int f[MAXN];
bitset<MAXN1>dis[MAXN1],sel;
inline int fa(int x){
	return (f[x]==x?x:f[x]=fa(f[x]));
}
inline void join(int x,int y){
	f[fa(x)]=fa(y);
}
int getd(int x,int y);
int get(){
	for(int i=1;i<=K;++i){
		f[i]=i;
	}
	for(int i=1;i<=K;++i){
		for(int j=i+1;j<=K;++j){
			if(dis[perm[i]][perm[j]])join(perm[i],perm[j]);
		}
	}
	int last1=0,last2=0;
	for(int i=1;i<=K;++i){
		if(last1){
			if(fa(perm[i])!=last1){
				if(last2){
					if(fa(perm[i])!=last2){
						return INT_MAX;
					}
				}
				else last2=fa(perm[i]);
			}
		}
		else last1=fa(perm[i]);
	}
	int r=0;
	for(int i=1;i<=N;++i){
		if(!sel[i]){
			int xx=INT_MAX;
			for(int j=1;j<=K;++j)xx=min(xx,getd(i,perm[j]));
			r=max(r,xx);
		}
		
	}
	return r;
}
int dfs(int now,int idx){
	if(now>K)return get();
	int ans=INT_MAX;
	for(int i=idx+1;i<=N;++i){
		sel[idx]=1;
		perm[now]=idx;
		ans=min(ans,dfs(now+1,i+1));
		sel[idx]=0;
	}
	return ans;
}
int d[MAXN],lca_[MAXN][35];
int init(int u,int fa){
	d[u]=d[fa]+1,lca_[u][0]=fa;
	for(int i=1;i<=30;++i){
		lca_[u][i]=lca_[lca_[u][i-1]][i-1];
	}
	for(int v=1;v<=N;++v){
		if(v==fa)continue;
		if(dis[u][v])init(v,u);
	}
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=30;~i;--i){
		if((1<<i)<=d[x]-d[y])x=lca_[x][i];
	}
	for(int i=30;~i;--i){
		if(lca_[x][i]!=lca_[y][i])x=lca_[x][i],y=lca_[y][i];
	}
	return lca_[x][0];
}
int getd(int x,int y){
	int lca1=lca(x,y);
	return (d[x]-d[lca1])+(d[y]-d[lca1]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>C>>T;
	while(T--){
		memset(d,0,sizeof(d));
		memset(lca_,0,sizeof(lca_));
		cin>>N>>K;
		for(int i=1;i<=N;++i){
			// edge[i].clear();
			dis[i].reset();
		}
		for(int i=1;i<N;++i){
			int u,v;
			cin>>u>>v;
			// edge[u].push_back(v);
			// edge[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
			
		}
		init(1,0);
		cout<<dfs(1,0)<<'\n';
	}
	
	
	return 0;
}
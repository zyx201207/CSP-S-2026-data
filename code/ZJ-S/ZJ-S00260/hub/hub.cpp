#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,vis[15],e[15][15];
void dfs(int u,int fa,int S){
	vis[u]=1;
	for(int v=1;v<=n;v++)
		if(v!=fa&&e[u][v]&&S&(1<<(v-1)&&!vis[v]))
			dfs(v,u,S);
}
int dfs2(int u,int fa,int x){
	if(u==x) return 0;
	for(int v=1;v<=n;v++)
		if(v!=fa){
			int d=dfs2(v,u,x);
			if(d<0) continue;
			else return d+1;
		}
	return -1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v; scanf("%lld%lld",&u,&v);
			e[u][v]=1,e[v][u]=1;
		}
		int ans=1000;
		for(int S=1;S<(1<<n);S++){
			int cnt=0;
			for(int j=0;j<n;j++)
				if(S&(1<<j))
					cnt++;
			if(cnt!=k) continue;
			memset(vis,0,sizeof(vis));
			cnt=0;
			for(int i=1;i<=n;i++) if(S&(1<<(i-1))) dfs(i,0,S),cnt++;
			if(cnt>2) continue;
			int res=0;
			for(int i=1;i<=n;i++){
				if(S&(1<<(i-1))) continue;
				int tmp=0;
				for(int j=1;j<=n;j++)
					if(S&(1<<(j-1)))
						tmp=min(dfs2(i,0,j),tmp);
				res=max(res,tmp);
			}
			ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

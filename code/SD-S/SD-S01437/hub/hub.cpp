#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n,k;
vector<int>e[N];
int mark[N],vis[N];
void dfs(int u){
	vis[u]=1;
	for(int v:e[u])if(mark[v]&&!vis[v])dfs(v);
}
int dis(int u,int op){
	vis[u]=op;
	if(mark[u])return 0;
	int res=1e9;
	for(int v:e[u])if(vis[v]!=op)res=min(res,dis(v,op)+1);
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k)continue;
			for(int j=1;j<=n;j++)vis[j]=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)mark[j+1]=1;
				else mark[j+1]=0;
			}
			int cnt=0;
			for(int j=1;j<=n;j++)if(mark[j]&&!vis[j])cnt++,dfs(j);
			if(cnt>2)continue;
			int res=0;
			for(int j=1;j<=n;j++)if(!mark[j])res=max(res,dis(j,j));
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//Shiina Taki

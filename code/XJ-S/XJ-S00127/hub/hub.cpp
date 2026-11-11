#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int C,T;
int n,k;
vector<int> e[105];
int f[105],dis[105];
bool vis[105];

void dfs(int u){
	if(!f[u]||vis[u])return;
	vis[u]=1;
	for(int v:e[u])dfs(v);
}
void ddd(int u,int fa){
	if(f[u])dis[u]=0;
	for(int v:e[u]){
		dis[v]=min(dis[v],dis[u]+1);
		if(v!=fa)ddd(v,u);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&C,&T);
	while(T--){
		int ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=3;i<(1<<n);++i){
			int sum=0,cnt=0,res=0;
			for(int j=0;j<n;++j){
				f[j+1]=(i>>j)&1;
				sum+=f[j+1];
			}
			if(sum!=k)continue;
			memset(vis,0,sizeof vis);
			memset(dis,0x3f,sizeof dis);
			for(int j=1;j<=n;++j){
				if(f[j]&&!vis[j]){
					++cnt;
					if(cnt>2)break;
					dfs(j);
					ddd(j,0);
				}
			}
			if(cnt>2)continue;
			for(int j=1;j<=n;++j){
				res=max(res,dis[j]);
			} 
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

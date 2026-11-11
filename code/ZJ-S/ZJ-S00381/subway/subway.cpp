#include<bits/stdc++.h>
using namespace std;
int C,n,m,d,q,k,g[500005][25],c[500005],t[20005][505],nxt[20005][505],now,pre,x,y;
long long w[500005],cnt,ans;
void dfs(int u,int v,int p,long long cnt){
	if(u==v){
		cnt+=(long long)t[v][p];
		if(ans==-1) ans=cnt;
		else ans=min(ans,cnt);
//		printf("%lld %lld\n",cnt,ans);
		return;
	}
	if(u==x){
		for(int i=1;i<=c[u];i++){
			if(nxt[u][g[u][i]]==0) continue;
			dfs(nxt[u][g[u][i]],v,g[u][i],cnt+(long long)t[u][g[u][i]]);
		}
		return;
	}
	for(int i=1;i<=c[u];i++){
		if(nxt[u][g[u][i]]==0) continue;
		if(g[u][i]!=p){
			dfs(nxt[u][g[u][i]],v,g[u][i],(long long)cnt+t[u][p]+t[u][g[u][i]]);
		}else dfs(nxt[u][g[u][i]],v,p,cnt);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&C);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&now);
			scanf("%d",&t[now][i]);
//			printf("%d %d\n",now,t[now][i]);
			c[now]++;
			g[now][c[now]]=i;
			if(j==1) pre=now;
			else nxt[pre][i]=now,pre=now;
		}
	}
//	for(int i=1;i<=m;i++){
//		printf("%d\n",i);
//		for(int j=1;j<=c[i];j++){
//			printf("%d %d %d\n",g[i][j],nxt[i][g[i][j]],t[i][g[i][j]]);
//		}
//	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=-1;
		dfs(x,y,0,0);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
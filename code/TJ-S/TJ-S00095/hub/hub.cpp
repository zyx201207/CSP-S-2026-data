#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,b,ans;
int head[8005],ver[8005],Next[8005],tot,dis[8005];
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int vis[8005];
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(vis[y]==1){
			continue;
		}
		dis[y]=dis[x]+1;
		dfs(y);
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		memset(head,-1,sizeof(head));
		memset(ver,0,sizeof(ver));
		memset(Next,0,sizeof(Next));
		tot=0;
		ans=1e9+7;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dis[1]=1;
		dfs(1);
		for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}
		cout<<"\n";
		if(k==n){
			printf("0\n");
			continue;
		}
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				for(int o=1;o<=n;o++){
					if(o==i||o==j){
						continue;
					}
					int maxd=max(dis[o],dis[i]);
					int maxdd=max(dis[o],dis[j]);
					int mind=min(dis[o],dis[i]);
					int mindd=min(dis[o],dis[j]);
					int d1=maxd-(mind-1)+1;
					int d2=maxdd-(mindd-1)+1;
					maxx=max(maxx,min(d1,d2));
				}
				ans=min(ans,maxx);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//萧瑟秋风今又是，换了人间。 

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1024;
int c,t,n,k,h[N],cnt,d[N],f[20][N],ans,d2[M][M];
bool vis[N];
struct Edge{
	int x,r;
}a[N<<1];
void dfs(int u){
	for(int i=h[u];i;i=a[i].r){
		if(a[i].x!=f[0][u])f[0][a[i].x]=u,d[a[i].x]=d[u]+1,dfs(a[i].x);
	}
}
void dfs2(int u,int j){
	vis[u]=1;
	for(int i=h[u];i;i=a[i].r){
		if(!vis[a[i].x]&&(j>>a[i].x-1&1))dfs2(a[i].x,j);
	}
}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k),cnt=1,ans=n;
		for(int i=1;i<=n;i++)h[i]=f[0][i]=0;
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			a[cnt].x=v,a[cnt].r=h[u],h[u]=cnt++,a[cnt].x=u,a[cnt].r=h[v],h[v]=cnt++;
		}
		dfs(1);
		for(int i=1;i<20;i++){
			for(int j=1;j<=n;j++)f[i][j]=f[i-1][f[i-1][j]];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int u=i,v=j;
				if(d[u]<d[v])swap(u,v);
				for(int k=0;k<20;k++){
					if(d[u]-d[v]>>k&1)u=f[k][u];
				}
				if(u==v){
					d2[i][j]=d[i]+d[j]-2*d[u];
					continue;
				}
				for(int k=19;k>=0;k--){
					if(f[k][u]!=f[k][v])u=f[k][u],v=f[k][v];
				}
				d2[i][j]=d[i]+d[j]-2*d[f[0][u]];
			}
		}
		for(int i=1;i<(1<<n);i++){
			int s=0;
			for(int j=0;j<n;j++){
				if(i>>j&1)s++;
				vis[j+1]=0;
			}
			if(s!=k)continue;
			s=0;
			for(int j=0;j<n;j++){
				if((i>>j&1)&&!vis[j+1])dfs2(j+1,i),s++;
			}
//			if(i==322)printf("%d\n",s);
			if(s>2)continue;
			s=0;
			for(int j=1;j<=n;j++){
				int p=n;
				for(int k=0;k<n;k++){
					if(i>>k&1)p=min(p,d2[j][k+1]);
				}
				s=max(s,p);
			}
//			printf("%d:%d\n",i,s);
			ans=min(ans,s);
		}
		printf("%d\n",ans);
	}
}
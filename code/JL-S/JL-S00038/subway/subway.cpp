#include <bits/stdc++.h>
using namespace std;
long long a[125255][505];
int w[125255];
int c,n,m,d,q;
long long dis(int st,int en){
	long long dis[m+1],vis[m+1];
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	while(vis[en]==0){
		int u,mib=1e9+5;
		for(int i=1;i<=m;i++){
			if(mib>dis[i] && vis[i]==0){
				mib=dis[i];
				u=i;
			}
		}
		vis[u]=1;
		//cout<<u<<endl;
		for(int i=1;i<=n;i++){
			if(a[u][i]==0)continue;
			for(int j=1;j<=m;j++){
				if(a[j][i]!=0){
					dis[j]=min(dis[u]+a[u][i]+a[j][i],dis[j]);
				}
			}
		}
	}
	return dis[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int zd,ti;
			scanf("%d",&zd);
			scanf("%d",&ti);
			a[zd][i]=ti;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=dis(x,y)+w[x]+w[y];
		printf("%d",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
}

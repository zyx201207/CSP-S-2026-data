#include<bits/stdc++.h>
using namespace std;
long long T, n, k, c;
long long u, v;
long long dis[1000][1000];
long long ans;
int main(){
	freopen("hug.in","r",stdin);
	freopen("hug.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		memset(dis,0x3f,sizeof(dis));
		for(long long i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			dis[u][v]=dis[v][u]=1;
		}
		for(long long i=1;i<=n;i++)
			dis[i][i]=0;
		for(long long k=1;k<=n;k++)
			for(long long i=1;i<=n;i++)
				for(long long j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ans=1e18;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(i!=j)
					ans=min(ans,dis[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}

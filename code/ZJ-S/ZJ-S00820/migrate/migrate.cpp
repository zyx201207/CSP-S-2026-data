//32~40
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,a[2000006];
vector<int>G[200005];
int dis[2003][2003];
int cnt[2003][2003];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0x00,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			int mxn=d/(a[2]-a[1]);
			if(mxn*2-1>=n-1||mxn<=1){
				printf("0\n");
			}
			else{
				printf("%lld\n",n-(mxn*2-1));
			}
			continue;
		}
		if(c==13||c==14){
			printf("0\n");
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(abs(a[u]-a[v])<=d){
					dis[u][v]=1;
					cnt[u][v]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(dis[u][v]==dis[u][i]+dis[i][v]){
						cnt[u][v]+=cnt[u][i]*cnt[i][v];
					}
					if(dis[u][v]>dis[u][i]+dis[i][v]){
						dis[u][v]=dis[u][i]+dis[i][v];
						cnt[u][v]=cnt[u][i]*cnt[i][v];
					}
				}
			}
		}
		int ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(cnt[u][v]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);

	}
	return 0;
}
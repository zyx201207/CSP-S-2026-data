#include<bits/stdc++.h>
using namespace std;
int c,t,n,dis[305][305];
long long a[2000005],d,cnt[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=6){
		while(t--){
			long long ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			for(int i=0;i<=300;i++){
				for(int j=0;j<=300;j++){
					dis[i][j]=1e9+7;
					cnt[i][j]=0;
				}
			}
			for(int i=0;i<=300;i++){
				dis[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						dis[i][j]=1;
						dis[j][i]=1;
						cnt[i][j]=1;
						cnt[j][i]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dis[i][j]==dis[i][k]+dis[k][j]&&k!=i&&k!=j){
							cnt[i][j]++;
						}
						else if(dis[i][j]>dis[i][k]+dis[k][j]&&k!=i&&k!=j){
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						}
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<cnt[i][j]<<"\n";
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

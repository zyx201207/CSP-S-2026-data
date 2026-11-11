#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=310;
int n,x[N],dis[N][N],cnt[N][N],d,c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				dis[i][j]=(x[j]-x[i]<=d)?1:1e18;
				cnt[i][j]=(x[j]-x[i]<=d)?1:0;
			}
		for(int l=2;l<=n;l++)
			for(int i=1;i+l-1<=n;i++){
				int j=i+l-1;
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(dis[i][k]+dis[k][j]==dis[i][j])
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}


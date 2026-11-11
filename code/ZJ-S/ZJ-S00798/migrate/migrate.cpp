#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,c,t,a[2000005],last[2000005],dis[5005][5005],cnt[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			scanf("%lld %lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			if(n==1){
				printf("%lld\n",0);
				continue;
			}
			a[0]=-4e18;
			int ans=0;
			for(int i=1;i<=n;i++){
				last[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=1e18;
					cnt[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				dis[i][i]=0;
				for(int j=i+1;j<=n;j++){
					if(dis[i][max(last[j],i)]>=1e18) dis[i][j]=1e18;
					else dis[i][j]=dis[i][max(last[j],i)]+1;
				}
			}
			for(int i=1;i<n;i++){
				cnt[i][i]=1;
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]>=1e18) break;
					for(int k=max(last[j],i);k<j;k++){
						if(dis[i][k]>dis[i][j]-1) break;
						cnt[i][j]+=cnt[i][k];
					}
					if(cnt[i][j]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	else{
		while(t--){
			scanf("%lld %lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			if(n==1){
				printf("%lld\n",0);
				continue;
			}
			int x=a[2]-a[1];
			int k=d/x;
			if(k<=1){
				printf("%lld\n",0);
				continue;
			}
			printf("%lld\n",max(0ll,n-(2*k-1)));
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,x[2000005],d,ans,c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			a[i]=x[i]-x[i-1];
		}
		long long sum=0;
		for(int i=1;i<n;i++){
			sum=0;
			int j;
			for(j=i+1;j<=n;j++){
				sum+=a[j];
				if(sum>d){
					break;
				}
			}
			long long ma,mi;
			ma=a[j-1]+a[j-2];
			mi=a[j-1];
			sum=0;
			for(;j<=n;j++){
				sum+=a[j];
				if(sum+ma<=d)continue;
				if(sum+mi>d)break;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
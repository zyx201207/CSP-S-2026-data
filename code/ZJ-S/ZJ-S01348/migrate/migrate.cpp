#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[1000009];
long long dp[5009][5009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		long long n,k;
		long long h=1;
		long long l=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		l=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=l){
				h=0;
			}
		}
		if(a[n]-a[1]<=k){
			cout<<0<<"\n";
		}else{
			if(h){
				if(2*l<=k){
					k/=l;
					k=k*2-1;
					cout<<n-k<<"\n";
				}else{
					cout<<0<<"\n";
				}
			}else{
				l=0;
				for(int i=2;i<=n;i++){
					l=max(l,a[i]-a[i-1]);
				}
				if(l<=k){
					cout<<0<<"\n";
				}else{
					long long sum=0;
					memset(dp,0,sizeof(dp));
					for(int i=1;i<=n;i++){
						for(int j=i+1;j<=n;j++){
							if(a[j]-a[i]<=k){
								dp[i][j]=1;
							}
						}
					}
					for(int i=1;i<=n;i++){
						for(int j=1;j<=n;j++){
							for(int k=1;k<=n;k++){
								dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
							}
						}
					}
					for(int i=1;i<=n;i++){
						for(int j=i+1;j<=n;j++){
							if(dp[i][j]==2 && j-i!=2*k){
								sum++;
							}
						}
					}
					cout<<sum<<"\n";
				}
			}
		}
	}
	return 0;
}

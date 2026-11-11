#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		long long l = -1,r = i;
		while(l+1<r){
			int mid = (l+r)/2;
			if((i-mid)*a[i]-(sum[i]-sum[mid]) <= m){
				r = mid;
			}else{
				l = mid;
			}
		}ans = max(ans,i-r);
	}printf("%lld",ans);

}

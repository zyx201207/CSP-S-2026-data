#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={},s[500005]={},ans=0;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<m){
				r=mid;	
			}else if((i-mid+1)*a[i]-(s[i]-s[mid-1])>m){
				l=mid+1;
			}else{
				l=r=mid;
			}
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,k=0;
		while(l<=r){
			long long mid=(l+r)/2;
			k=(a[i]*(i-mid)-s[i-1]+s[mid-1]);
			if(k<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(l<=i)ans=max(i-l+1,ans);
	}
	printf("%lld",ans);
	return 0;
} 

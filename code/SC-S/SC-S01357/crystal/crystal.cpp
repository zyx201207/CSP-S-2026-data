#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],maxx,minn=INT_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);
	if(minn<0)
		for(int i=1;i<=n;i++) a[i]+=abs(minn);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if((i-mid)*a[i]>s[i-1]-s[mid-1]+m){
				l=mid+1;
			}else{
				maxx=max(maxx,i-mid+1);
				r=mid-1;
			}
		}
	}
	printf("%lld",maxx);
	return 0;
}
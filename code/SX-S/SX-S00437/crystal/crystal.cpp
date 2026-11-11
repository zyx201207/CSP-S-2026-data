#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long l=1ll,rty=0ll,mx=0ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		rty+=(i-l)*(a[i]-a[i-1]);
		while(l<i&&rty>m){
			rty-=(a[i]-a[l]);
			l++;	
		}
		mx=max(mx,i-l+1);
	}
	printf("%lld",mx);
	return 0;
}

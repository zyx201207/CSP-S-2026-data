#include<bits/stdc++.h>
#define rep(i,a,b) for(long long i=(a);i<=(b);++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=5e5+7;
long long n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n){
		s[i]=s[i-1]+a[i];
	}
	rep(i,1,n){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r+1)/2;
			if(mid*a[i]-(s[i]-s[i-mid])<=m) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l);
	}
	printf("%lld\n",ans);
    return 0;
}

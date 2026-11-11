#include <bits/stdc++.h>
using namespace std;
long long n,k,x[500010],p=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;++i) scanf("%lld",&x[i]);
	sort(x+1,x+1+n);
	p=1;
	for(long long i=1;i<=n;++i){
		k-=(x[i]-x[i-1])*(i-p);
		while(k<0){
			k+=x[i]-x[p];
			++p;
		}
		ans=max(ans,i-p+1);
	}
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) ++j;
		ans=max(ans,1ll*i-j+1);
	}
	printf("%lld",ans);
	return 0;
}

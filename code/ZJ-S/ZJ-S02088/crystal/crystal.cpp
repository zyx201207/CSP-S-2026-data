#include<bits/stdc++.h>
using namespace std;
long long n,m,p[500010],ge,x,ans=1,fei;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	sort(p+1,p+1+n);
	ge=1;
	for(int i=2;i<=n;i++){
		fei+=ge*(p[i]-p[i-1]);
		while(fei>m){
			--ge;
			fei-=p[i]-p[i-ge];
		}
		ans=max(ans,ge);
		++ge;
	}
	printf("%lld",ans+1);
	return 0;
}//rp=2e9

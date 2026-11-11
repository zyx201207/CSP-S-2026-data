#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a,b,cha,e;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
scanf("%lld %lld",&c,&t);
while(t--){
	scanf("%lld %lld",&n,&d);
	scanf("%lld %lld",&a,&b);
	cha=b-a;
	e=d/cha;
	for(long long i=2;i<n;i++)scanf("%lld",&b);
	if(e==0ll||e==1ll)printf("%lld\n",0ll);
	else printf("%lld\n",max(0ll,n+1ll-(e*2ll)));
}
return 0;
}

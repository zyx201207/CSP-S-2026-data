#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,uu,flag,m;
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
scanf("%lld %lld",&c,&t);
while(t--){
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<n;i++)scanf("%lld %lld",&u,&v);
	m=(n+3ll)/2ll;
	if(k<n)printf("%lld\n",(m-k+3ll)/4ll);
	else printf("0\n");
}
return 0;
}

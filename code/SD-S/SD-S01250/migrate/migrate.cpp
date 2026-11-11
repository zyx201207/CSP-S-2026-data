#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[110];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		printf("%lld\n",n*(n-1)/2);
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
int x[500005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		int d=x[2]-x[1];
		if(k<d*2 or k>=d*3) printf("0\n");
		else printf("%lld\n",n-3);
		continue;
	}
	return 0;
}
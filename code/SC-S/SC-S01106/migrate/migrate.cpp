#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000006];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int x,y,z;
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		x=n*(n-1)/2;
		printf("%lld\n",x);
	}
	return 0;
}
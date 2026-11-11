#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n;
	long long d,a1,a2;
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		scanf("%lld%lld",&a1,&a2);
		int cha=a2-a1;
		for(int i=3;i<=n;i++) scanf("%lld",&a1);
		if(2*cha<=d&&d<3*cha) printf("%d\n",n-3);
		else puts("0");
	}
	return 0;
}

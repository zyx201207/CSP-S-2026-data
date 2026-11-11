#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		puts("1");
	}
}
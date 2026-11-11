#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],sum;
short b;

int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n,&m);
	for (int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++)
	{
		for (int j=1;i<=i-1;j++)  sum+=a[i]-a[j];
		if (sum>m)
			{
				printf("%lld",i-1); 
				break;
			}
			if (sum==m)
			{
				printf("%lld",i);
				break;
			}
			if (i==n)
			{
				printf("%lld",n);
				break;
			}	
	} 
	
	return 0;
}
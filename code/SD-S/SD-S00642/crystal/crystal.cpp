#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
long long m,a[500005],c,answ;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		long long ans=0;
		long long c=m;
		while(a[i]==a[i+1]) i++;
		for(int j=i;j>=2;j--)
		{
			if(c>=a[i]-a[j-1])
			{
				ans++;
				c-=a[i]-a[j-1];
			}
		}
		answ=max(ans,answ);
	}
	printf("%d",answ+1);
	return 0;
}


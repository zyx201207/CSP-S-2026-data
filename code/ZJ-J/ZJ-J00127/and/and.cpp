#include<bits/stdc++.h>
using namespace std;
struct mod{
	long long number;
	long long number1;
	long long t;
}a[200010];
bool cmp(mod a,mod b)
{
	return a.t>b.t;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a[i].number);
		a[i].number1=a[i].number;
	}
	for(i=1;i<=31;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i].number1%2==1)
			{
				a[i].t++;
			}
			a[i].number1/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	int sum=a[1].number;
	for(i=2;i<=m;i++)
	{
		sum+=a[i].number;
	}
	printf("%lld",sum);
	return 0;
}
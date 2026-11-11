#include<bits/stdc++.h>
using namespace std;
int c[1000005],w[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,d=0;
	scanf("%lld %lld",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(c[i]>c[j])
			{
				swap(c[i],c[j]);
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		b-=(i-1)*(c[i]-c[i-1]);
		if(b<0)
		{
			break;
		}
		d++;
	}
	printf("%lld",d);
}


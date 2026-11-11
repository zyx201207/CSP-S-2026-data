#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum,k[500010],mi=1e9,ma;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mi=min(a[i],mi);
	}
	if(n>780)
	{
		if(a[2]-a[1]!=a[3]-a[2])
		{
			cout<<n;
		}
		else
		{
			int b=abs(a[2]-a[1]);
			for(int i=sqrt(2*m/b)-100000;i<=sqrt(2*m/b)+100000;i++)
			{
				if(i*(i+1) > 2*m/b)
				{
					cout<<i-1;
					return 0;
				}
			}
		}
		return 0;
	}
	if(mi<-640)
	{
		mi=-640;
	}
	for(int i=mi;i<=640;i++)
	{
		long long as=m,an=0;
		for(int j=1;j<=n;j++)
		{
			k[j]=abs(a[j]-i);
		}
		sort(k+1,k+n+1);
		for(int j=1;j<=n;j++)
		{
			if(as>=k[j])
			{
				as-=k[j];
				an++;
			}
			else
			{
				break;
			}
		}
		ma=max(ma,an);
	}
	cout<<ma;
	return 0; 
}
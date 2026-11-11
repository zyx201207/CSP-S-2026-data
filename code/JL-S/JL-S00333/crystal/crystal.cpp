#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int n,ok=1,os=1;
long long m,sum=0,cnt=0,ans=0,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			os=0;
		}
	}
	long long ans=a[2]-a[1];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		if(s[i]!=ans)
		{
			ok=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(m<s[i])
		{
			cout<<1;
			return 0;
		}
	}
	//cout<<ans<<endl;
	if(ans!=1)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=ans*i;
			if(m<=sum)
			{
				cout<<i;
				return 0;
			}
		}
	}
	if(ans==1)
	{
		for(int i=1;i<=n;i++)
		{
			num+=i;
			if(m<num)
			{				
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
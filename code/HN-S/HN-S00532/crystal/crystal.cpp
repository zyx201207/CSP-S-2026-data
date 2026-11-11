#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N],n,m,sum,ans,f,k;
void B()
{
	for(int i=1;sum<=m;i++)
	{
		sum+=i;
		sum+=(i-1)*k;
		ans=i;
	}
	cout<<ans;
}
void A()
{
	for(int i=1;sum<=m;i++)
	{
		sum+=i;
		ans=i;
	}
	cout<<ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			f=114514;
		}
		else
		{
			f=67;
		}
	}
	sort(a+1,a+1+n);
	if(n>=N and f==114514)
	{
		k=a[2]-a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]==k)
			{
				f=5267;
			}
			else
			{
				f=10086;
			}
		}
		if(f=5267)
		{
			B();return 0;
		}
		A();return 0;
	}
	cout<<n;
	return 0; 
}

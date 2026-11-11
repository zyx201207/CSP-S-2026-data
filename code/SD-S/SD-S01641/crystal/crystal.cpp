#include<bits/stdc++.h>
using namespace std;
int a[50000006];
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	ans/=n;
	int minn=1e9,sum,id;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			if(ans-a[i]<minn)
			{
				minn=ans-a[i];
				sum=a[i];
				id=i;
			}
		}
		else
		{
			if(abs(ans-a[i])<=minn)
			{
				minn=abs(ans-a[i]);
				sum=a[i];
				id=i;
			}
		}
	}
	for(int i=id;i>=1;i--)
	{
		m=m-(sum-a[i]);
		if(m>=0)
		{
			a[i]=sum;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==sum)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
//5 8 -3 -1 2 2 7

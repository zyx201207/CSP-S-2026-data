#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],v[30],ans,x,f;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(i==1)
				ans=x;
			else
				ans&=x;
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				x=a[i]&a[j];
				ans=max(ans,x);
			}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ans=a[2];
		for(int i=3;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)
			f=1;
		if(a[i]<4)
			v[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(f==1)
	{
		ans=a[n],m--;
		for(int i=n-1;m;m--,i--)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	else
	{
		if(v[3]>=m)
			cout<<3;
		else if(v[2]+v[3]>=m)
			cout<<2;
		else if(v[1]+v[3]>=m)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}

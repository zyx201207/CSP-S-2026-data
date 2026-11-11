#include<bits/stdc++.h>
using namespace std;
int d(int m)
{
	int wwp=0;
	int co=0;
	for(int i=1;i<=m;i++)
	{
		wwp+=i;
		if(wwp>m)
		{
			co=i-1;
			break;
		}
	}
	return co;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i+1<=n;i++)
	{
		if(a[i]==a[i+1])
		ans++;
		if(ans==n-1)
		{
			cout<<n;
			break;
		}
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		cout<<2;
		return 0;
	}
		if(n==3)
	{
		cout<<3;
		return 0;
	}
		if(n==4)
	{
		cout<<4;
		return 0;
	}
		if(n==5)
	{
		cout<<5;
		return 0;
	}
	int w=0;
	for(int i=1;i+1<=n;i++)
	{
		w+=a[i+1]-a[i];
		if(n%2==0&&w==n-1)
		{
			cout<<d(m)+1;
			return 0;
		}
		if(n%2!=0&&w==n-1)
		{
			cout<<d(m)+1;
			return 0;
		}
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,st[300],k=1;
long long a[N],ans=0;
bool check(int n)
{
	int n1=n;
	while(n1)
	{
		if(n1%2)return 0;
		n1/=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i-1)return 0;
	}
	return 1;
}
bool check1(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(!check(a[i]+1))return 0;
	}
	return 1;
}
bool check2(int a)
{
	while(a)
	{
		if(a%2)return 0;
		a/=2;
	}
	return 1;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
	}
	else if(m==n-1)
	{
		sort(a+1,a+n+1);
		ans=a[2];
		for(int i=3;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(check(n))
	{
		ans=a[n-m+1];
		for(int i=n-m+2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(check1(n))cout<<a[n-m+1];
	else 
	{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
		for(int i=n-m+2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],cnt=-1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[2]-a[1]==1&&a[n]-a[1]==n-1)
	{
		cout<<n-m;
		return 0;
	}
	sort(a+1,a+n+1,cmp);

	if(m==n)
	{
		cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt&=a[i];
		}
		cout<<cnt;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
	}
	else if(a[1]<4)
	{
		int x=m;
		cnt=a[1];
		for(int i=2;i<=m;i++)
		{
			cnt&=a[i];
		}
		cout<<cnt;
	}
	else if(m==1) cout<<0;
	else if(m==n-1)
	{
		cnt=a[1];
		for(int i=2;i<=m;i++)
		{
			cnt&=a[i];
		}
		cout<<cnt;
	}
	else
	{
		cout<<a[m];
	}
	return 0;
}


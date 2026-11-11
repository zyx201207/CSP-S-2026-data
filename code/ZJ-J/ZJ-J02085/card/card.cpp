#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],b[100001],ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5&&m<=2)
	{
		if(n==1)
		{
			if(a[1]==1||a[1]==2)
			{
				cout<<1;
				return 0;
			}
			cout<<0;
			return 0;
		}
		if(n==2)
		{
			if(m==1)
			{
				if(a[1]==1&&a[2]==1)
				{
					cout<<1;
					return 0;
				}
				if(a[1]==1||a[2]==1)
				{
					cout<<2;
					return 0;
				}
			}
			else
			{
				if(a[1]==1&&a[2]==1)
				{
					cout<<1;
					return 0;
				}
				if(a[1]==2&&a[2]==2)
				{
					cout<<1;
					return 0;
				}
				if((a[1]==2&&a[2]==1)||(a[1]==1&&a[2]==2))
				{
					cout<<3;
					return 0;
				}
				if(a[1]==1||a[1]==2)
				{
					cout<<1;
					return 0;
				}
				if(a[2]==1||a[2]==2)
				{
					cout<<2;
					return 0;
				}
				cout<<0;
				return 0;
			}
		} 
	}
	if(m<=2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==1||a[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]!=a[j-1])
			{
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans+=b[i];
	}
	cout<<ans;
	return 0;
}



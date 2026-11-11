#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];

bool check()
{
	for (int i=1;i<=n;i++)
	{
		bool flag=false;
		for (int j=0;j<=30;j++)
			if(pow(2,j)-1==a[i])
				flag=true;
		if (flag==false)
			return false;
	}
	return true;
}
bool fan(int o)
{
	for (int i=0;i<=30;i++)
	{
		if (pow(2,i)==n)
			return true;
	}
	return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);

	if (m==1)
		cout<<a[n];
	else if (m==2 && n<8000)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			maxn=max(maxn,(a[i]&a[j]));
		}
		cout<<maxn;
	}
	else if (m==n)
	{
		int solve=a[1];
		for (int i=2;i<=n;i++)
		{
			solve=solve&a[i];
		}
		cout<<solve;
	}
	else if (check()==true)
	{
		int solve=a[n];
		for (int i=n-1;i>=n-m+1;i--) 
		{
			solve=solve&a[i];
		}
		cout<<solve;
	}
	else if (fan(n))
		cout<<n-m;
	else if (a[n]<4)
	{
		cout<<1;
	}
	else if (m==3)
	{
		int maxn=-1;
		for (int i=1;i<=n-2;i++)
		{
			for (int j=i+1;j<=n-1;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					maxn=max(maxn,a[i]&a[j]%a[k]);
				}
			}
		}
		cout<<maxn;
	}
	else if (m==4)
	{
		int maxn=-1;
		for (int i=1;i<=n-3;i++)
		{
			for (int j=i+1;j<=n-2;j++)
			{
				for (int k=j+1;k<=n-1;k++)
				{
					for (int h=k+1;h<=n;h++)
					{
						maxn=max(maxn,a[i]&a[j]&a[k]%a[h]);
					}
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}

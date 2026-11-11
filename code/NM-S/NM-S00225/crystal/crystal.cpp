#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	int r[n][n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>i&&a[j]-a[i]<=m)
			{
				r[i][j] = a[j]-a[i];
			}
			else
			{
				r[i][j] = 0;
			}
		}
	}
	int x=0,dw=0;
	for(int j=0;j<n;j++)
	{
		int sum=0;
		int y=m;
		for(int i=n-1;i>=0;i--)
		{
			if(r[i][j]!=0&&y-r[i][j]>=0)
			{
				sum++;
				y-=r[i][j];
			}
		}
		if(sum>x)
		{
			dw = j;
			x = sum;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[dw])
		{
			sum++;
		}
	}
	cout<<x+sum;
	return 0;
}

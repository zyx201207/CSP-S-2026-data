#include<bits/stdc++.h>
using namespace std;
int a[50100];
int b[50100];
int c[50100][50100];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1-i;j++)
		{
			c[i][j]=(j-1)*b[i+j-2]+c[i][j-1];
			if(c[i][j]>m)
			{
				j=j+n+i+1;
			}
			if(c[i][j]<=m&&j>ma)
			{
				ma=j;
			}
		}
		if(i==ma+1)
		{
			break;
		}
	}
	cout<<ma;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;


	int t[10005];
	char f[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int x=t[i];
		while(x>0)
		{
			if(x%2==0)
			{
				f[i]+='0';
			}
			if(x==1)
			{
				f[i]+='1';
			}
			x/=2;
		}
	}
	int maxv=0;
	int y[10005],r[10005];
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(f[i]=='1'&&f[j]=='1')
			{
				y[i]+='1';
			}
			else
			{
				y[i]+='0';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(y[i]>maxv)
		{
			maxv=y[i];
		}
	}
	int sum=0;
	int number=0;
	while(maxv>0)
	{
		int z=1;
		for(int i=1;i<=number;i++)
		{
			z*=2;
		}
		sum+=maxv%10*z;
		maxv/=10;
	}
	cout<<sum;
}
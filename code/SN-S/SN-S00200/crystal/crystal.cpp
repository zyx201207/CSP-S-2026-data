#include<bits/stdc++.h>
using namespace std;

const long long N=5e3+5;

int a[N];
long long d[N][N];
int n;
long long m;
bool cnt;
long long c;
long long e;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	c=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		e=a[i]-a[i-1];
		if(c!=e)
		{
			cnt=1;
			break;
		}
	}
	if(cnt==0)
	{
		if(c==0)
		{
			cout<<n;
			return 0;
		}
		long long k;
		k=m*2/c;
		for(int i=1;i<=n;i++)
		{
			if((i+1)*i==k)
			{
				cout<<(i+1);
				return 0;
			}
			if((i+1)*i>k)
			{
				cout<<i;
				return 0;
			}
		}
	}
	
	for(int i=1;i<=n-1;i++)
	{
		d[2][i]=a[i+1]-a[i];
	}
	
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			
			d[i][j]=d[i-1][j]+d[2][j+i-2]*(i-1);
		}
	}
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cout<<d[i][j]<<"	";
		}
		cout<<endl;
	}
	
	
	
	for(int i=n;i>=2;i--)
	{
		for(int j=n-i+1;j>=1;j--)
		{
			if(d[i][j]<=m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
	
		
}

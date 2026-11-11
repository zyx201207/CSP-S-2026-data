#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		int b=a[1];
		for(int i=2;i<=n;i++)
		{
			b=a[i]&b;
		}
		cout<<b;
	}
	else if(m==2)
	{
		int max=a[1]&a[2]; 
		int cnt;
		for (int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=a[i]&a[j];
				if(max<cnt)
				{
					max=cnt;
				}
			} 
		}
		cout<<max;
	}
	else if(m==1)
	{
		int max=a[1]; 
		int cnt;
		for (int i=2;i<=n;i++)
		{
			cnt=a[i];
			if(max<cnt)
			{
				max=cnt;
			}
		}
		cout<<max;
	}
	else if(m==n-1)
	{
		int max=a[1]; 
		int cnt=a[1];
		for(int i=2;i<n;i++)
		{
			max=max&a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					cnt=cnt&a[j];
					if(max<cnt)
					{
						max=cnt;
					}
				}	
			} 
		}
		
		cout<<max;
	}
	else 
	{
		int d=n-m;
		int max=a[1]; 
		int cnt=a[1];
		for(int i=2;i<n;i++)
		{
			max=max&a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for(int j=1;j<=d;j++)
			{
				if(j!=i)
				{
					cnt=cnt&a[j];
					if(max<cnt)
					{
						max=cnt;
					}
				}	
			} 
		}
		
		cout<<max;
	}
	return 0;
}

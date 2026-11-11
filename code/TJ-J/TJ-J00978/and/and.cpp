#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n+1];
		return 0;
	}
	int max=0;
	int cnt=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=a[i]&a[j];
				if(cnt>=max)
				{
					max=cnt;
				}
			} 
		} 
	}
	
	if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					cnt=a[i]&a[j]&a[k];
					if(cnt>=max)
					{
						max=cnt;
					}
				}
			} 
		} 
	}
	if(m=n)
	{
		cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
	}
	max=cnt;
	cout<<max;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],ans[500009],p;
bool flag[500009];
int main()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long t=1;t<=n;t++)
	{
		for(long long i=1;i<=m;i++)
		{
			flag[i]=true;
		}
		p=t;
		for(long long i=t;i<=n;i++)
		{
			for(long long j=p;j<i;j++)
			{
				if(a[j]==a[i]) 
				{
					for(long long x=j;x<i;x++)
					{
						flag[x]=false;
					}
					p=i;
					break;
				}
			}
		}
		for(long long i=t;i<=n;i++)
		{
			if(flag[i]) ans[a[i]]++;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}

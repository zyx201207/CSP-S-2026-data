#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N];
long long c[N];
int dfs(long long n,long long m)
{
	while(m>0)
	{
		for(int i=0;i<=n;i++)
		{
			a[i]+=2;
			m-=1;
			for(int j=0;j<n;j++)
			{
				if(a[i]==a[i+j])
				{
					return 1;
					break;
				}
				
			}
		}
		
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dfs(n,m))
			{
				c[j]+=1;
			}
			if(c[j]>c[j-1])
			{
				max=c[j];
			}
		}
	}
	cout<<max-2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

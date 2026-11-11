#include<bits/stdc++.h>
using namespace std;
long long b,c,d,e,f,n,m,a[100000],maxxx=1;
void dfs(long long dep,long long shu,long long And)
{
	
	if(shu==m)
	{
		maxxx=max(maxxx,And);
		return;
	}
	
	if(dep>n)
	{
		return;
	}
	dfs(dep+1,shu+1,And&a[dep]);
	dfs(dep+1,shu,And);
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		long long maxx=1;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==2)
	{
		long long maxx=1;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(i!=j)
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(m==(n-1))
	{
		int sum=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				if(i!=j)
				{
					sum&=a[i];
				}
			}
		}
		cout<<sum;
	}
	else 
	{
		dfs(1,0,0);
		cout<<maxxx;
    }  
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 3
//2 31 3 1 15 7


#include<bits/stdc++.h>
using namespace std;
int n,m;
int aa[200005];
int maxx;
void dfs(int i,int z,int s)
{
	if(z==m)
	{
		maxx=max(maxx,s);
		return ;
	}
	for(;i<=n-m+z+1;i++)
	{
		if(z==0)
		{
			dfs(i+1,1,aa[i]);
			dfs(i+1,0,1);
		}
		else
		{
			dfs(i+1,z+1,s&aa[i]);
			dfs(i+1,z,s);
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	if(n<=26)
	{
		dfs(1,0,1);
		cout<<maxx;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				maxx=max(maxx,aa[i]);
			}
			cout<<maxx;
		}
		if(m==n)
		{
			maxx=aa[1];
			for(int i=2;i<=n;i++)
			{
				maxx=maxx&aa[i];
			}
			cout<<maxx;
		}
		if(m==2)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					maxx=max(aa[i]&aa[j],maxx);
				}
			}
			cout<<maxx;
		}
	}
	else
	{
		bool t=1;
		for(int i=1;i<=n;i++)
		{
			if(aa[i]!=i-1)
			{
				t=0;
				break;
			}
		}
		if(t)
		{
			cout<<0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				maxx=max(maxx,aa[i]);
			}
			cout<<maxx;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200005];
int w[40];
int maxxx=-1;
void dfs(int x,int ans,int k)
{
	
	
	if(k==m)
	{
		maxxx=max(maxxx,ans);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(x==1)dfs(i+1,a[i],k+1);
		else dfs(i+1,ans&a[i],k+1);
	}
}

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
		cout<<a[n];
	}
	else if(m==2)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else if(n<=2000)
	{
		dfs(1,0,0);
		cout<<maxxx;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}

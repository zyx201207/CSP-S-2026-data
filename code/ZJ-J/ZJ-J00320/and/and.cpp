#include<bits/stdc++.h>
using namespace std;

int a[200000+10],ans,n,m;

void dfs(int x,int y,int z)
{
	if(y>m) return ;
	if(x>n)
	{
		if(y==m)
		{
			ans=max(ans,z);
		}
		return ;
	}
	dfs(x+1,y,z);
	dfs(x+1,y+1,z&a[x]);
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
	sort(a+1,a+n+1,greater<int>());
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		dfs(1,0,INT_MAX);
		cout<<ans;
		return 0;
	}
	else
	{
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}

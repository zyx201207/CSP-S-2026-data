#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
long long a[200005];
long long n,m,ans=0;
void dfs(int id,int l,long long num)
{
	if(l==m)
	{
		ans=max(ans,num);
		return;
	}
	for(int i=id+1;i<=n;i++)
	{
		dfs(id+1,l+1,num&a[i]);
	}
	return;
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
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans; 
	}
	else
	{
		dfs(1,0,a[1]);
		cout<<ans;
	}
	cout<<endl;
	return 0;
}

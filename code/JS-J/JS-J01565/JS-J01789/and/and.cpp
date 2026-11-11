#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
bool vis[200005];
int f(int a2,int b2)
{
	string a1="",b1="";
	while(a2)
	{
		a1=a1+char(a2%2+'0');
		a2/=2;
	}
	while(b2)
	{
		b1=b1+char(b2%2+'0');
		b2/=2;
	}
	int len=min(a1.size(),b1.size());
	string c1="";
	for(int i=0;i<len;i++)
	{
		if(a1[i]=='1'&&b1[i]=='1')
		{
			c1='1'+c1;
		}
		else
		{
			c1='0'+c1;
		}
	}
	int ans=0;
	for(int i=0;i<len;i++)
	{
		ans=ans*2+c1[i]-'0';
	}
	return ans;
}
int dfs(int dep)
{
	int ans=0;
	if(dep>m)
	{
		for(int i=1;i<m;i++)
		{
			ans=f(b[i],b[i+1]);
		}
		return ans;
	}
	for(int i=dep;i<=n-m+dep;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		b[dep]=a[i];
		vis[i]=1;
		ans=max(ans,dfs(dep+1));
		vis[i]=0;
	}
	return ans;
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
	cout<<dfs(1);
	return 0;
}

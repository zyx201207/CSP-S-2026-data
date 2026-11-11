#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,a[N],ans,f;
void dfs(long long i,long long g,long long s)
{
	if(g==m)ans=max(s,ans);
	if(i>n||g>m)
	{
		return;
	}
	if(s==0)
	{
		dfs(i+1,g+1,a[i]);
	}
	else if(s>0)
	{
		dfs(i+1,g+1,s&a[i]);
	}
	dfs(i+1,g,s);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>4)f=1;
	}
	if((n<=2000||f==0)&&m!=2&&m!=1&&n!=m+1)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i!=j)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		for(int i=1;i<=n;i++)ans=max(ans,ans&a[i]);
		cout<<ans;
	}
	else
	{
		dfs(1,0,0);
		cout<<ans; 
	}
	return 0;
}


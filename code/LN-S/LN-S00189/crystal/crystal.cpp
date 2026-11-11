#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
bool cmn(int x,int y)
{
	return x<y;
}
long long ans=0;
bool work()
{
	long long cha=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=cha)
		{
			return false;
		}
	}
	return true;
}
int dfs(int x)
{
	long long mm=m;
	long long anss=1;
	if(mm==0)
	{
		return anss;
	}
	
	for(int i=x-1;i>0;i--)
	{
		int cha=a[x]-a[i];
		if(mm>=cha)
		{
			mm-=cha;
			anss++;
		}
	}
	ans=max(ans,anss);
	if(x==n)
	{
		return 0;
	}
	return dfs(x+1);
}
int workk(int x)
{
	if((x<=n&&a[1]+a[x])*x/2<=m)
	{
		return(x+(n-x)/2);
	}
	else
	{
		return(x-(n-x)/2);
	}
	ans=x;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1,cmn);
	bool flag=work();
	if(flag==true)
	{
		workk(n/2);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

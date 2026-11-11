#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma;
bool b[200005];
void dfs(int x,int cnt)
{
	if(x!=1&&cnt<=ma) return ;
	if(x>m)
	{
		ma=max(ma,cnt);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i]&&a[i]>ma)
		{
			b[i]=true;
			if(x==1) dfs(x+1,a[i]);
			else dfs(x+1,cnt&a[i]);
			b[i]=false;
		}
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
	if((n<=20)||(n<=5000&&m==2))
	{
		dfs(1,0);
		cout<<ma;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==n)
	{
		ma=a[1];
		for(int i=2;i<=n;i++)
		{
			ma=ma&a[i];
		}
		cout<<ma;
		return 0;
	}
	else
	{
		dfs(1,0);
		cout<<ma;
		return 0;
	}
	return 0;
}

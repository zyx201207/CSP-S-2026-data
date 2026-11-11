#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum[200005],mx=-1000000000;
void dfs(int id,long long ans,int sum)
{
	if(sum==m+1)
	{
		mx=max(mx,ans);
		return;
	}
	if(id==n+1)
	{
		return;
	}
	dfs(id+1,ans,sum);
	if(ans==0)
	{
		dfs(id+1,a[id],sum+1);
	}
	else
	{
		dfs(id+1,ans&a[id],sum+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=0;
	bool bo=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)
		{
			bo=1;
		}
		maxn=max(maxn,a[i]);
	}
	if(!bo)
	{
		cout<<2;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(maxn==a[i])
			{
				continue;
			}
			mx=max(maxn&a[i],mx);
		}
		cout<<mx;
		return 0;	
	}
	dfs(0,0,0);
	cout<<mx;
	return 0;
}
//4 2
//3 15 12 12








 

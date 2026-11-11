#include<bits/stdc++.h>
using namespace std;
long long a[20010];
int vis[20010];
int n,m;
long long yu(long long a,long long b)
{ 
	long long c;
	int a1[110],b1[110];
	int cnta=1;
	int cntb=1;
	while(a!=0)
	{
		a1[cnta++]=a%2;
		a/=2;
	}
	cnta--;
	while(b!=0)
	{
		b1[cntb++]=b%2;
		b/=2;
	}
	cntb--;
	int cnt=0;
	for(int i=min(cnta,cntb);i>=1;i--)
	{
		int x;
		if(a1[i]==1&&b1[i]==1)
		{
			x=1;
		}
		else 
		{
			x=0;
		}
		c+=pow(x,cnt++);
	}
	return c;
}
int dfs(int depth,long long ans)
{
	if(depth==m+1)
	{
		return ans;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			long long ans1=dfs(depth+1,yu(a[i],ans));
			if(ans<ans1)
			{
				return ans1;
			}
			else
			{
				return ans;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	return 0;
}

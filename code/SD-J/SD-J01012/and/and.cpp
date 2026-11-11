#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,m,ans;
int a[N];
void dfs(int u,int sum,int an)
{
	if(u==n)
	{
		if(sum==m)
		{
			ans=max(ans,an);
		}
		return ;
	}
	dfs(u+1,sum+1,an&a[u]);
	dfs(u+1,sum,an);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2000)
	{
		if(m==1)
		{
			cout<<a[n];
			return 0;
		}
		if(m==2)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		dfs(1,0,1048575);
		cout<<ans;
	}
	else
	{
		cout<<a[n];
	}
	return 0;
}
//I AK CSP-J!!!


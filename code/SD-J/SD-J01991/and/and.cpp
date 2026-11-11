#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],m,n,ans=-1e18;
bool is[N];
void dfs(long long u,long long x)
{
	if(u==m) 
	{
		ans=max(ans,x);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(is[i]==0)
		{
			is[i]=1;
			if(u==0) dfs(u+1,a[i]);
			else dfs(u+1,x&a[i]);
			is[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	if(n<=2000)
	{
		if(m==n)
		{
			long long ans0=a[0];
			for(long long i=1;i<n;i++) ans0&=a[i];
			cout<<ans0;
			return 0;
		}
		dfs(0,0);
		cout<<ans;
	}
	else
	{
		if(m==n-1)
		{
			cout<<0;
			return 0;
		}
		for(long long i=0;i<n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	return 0;
}

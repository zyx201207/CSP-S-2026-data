#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ma;
ll memo[200005];
void dfs(ll x,ll y,ll ans)
{
	if(x>=n && y==0) 
	{
		if(ma==0) 
		{
			ma=ans;
			return ;
		}
		ma=max(ma,ans);
		return ;
	}
	else if(x>=n) return ; 
	if(y==m-1 && ans!=0)
	{
		ans=a[x];
	}
	dfs(x+1,y-1,ans&=a[x]);
	dfs(x+1,y,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	dfs(0,m,2147483647);
	cout<<ma;
	return 0;
}

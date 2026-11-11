#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
typedef long long LL;
LL n,m,ans,mx,mn;
LL a[N];
void dfs(LL x,LL step,LL h)
{
	if(step==m)
	{
		ans=max(ans,h);
	}
	else
	{
		for(int i=x+1;i<=n;i++)
		{
			dfs(i,step+1,h&a[i]);
		} 
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		mn&=a[i];
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	else if(m==n)
	{
		cout<<mn;
		return 0;
	}
	for(LL i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}

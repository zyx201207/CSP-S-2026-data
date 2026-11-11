#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans=-0x3f,b[200005];
void dfs(int k)
{
	if(k==m)
	{
		int cnt=0,l=2;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				cnt=a[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==l)
			{
				cnt&=a[i];
				i=1;
				l++;
			}
		}
		ans=max(cnt,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=k+1;
			dfs(k+1);
			b[i]=0;
		}
	}
	return ;
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
	dfs(0);
	cout<<ans;
	return 0;
}
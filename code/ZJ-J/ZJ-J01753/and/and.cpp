#include<bits/stdc++.h>
using namespace std;
long long ans,a[200010],f[200010],n,m;
void dfs(int deep,long long s,int k)
{
	if(deep==m+1)
	{
		ans=max(ans,s);
		return ;
	}
	for(int i=k;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			if(deep==1) dfs(deep+1,a[i],i+1);
			else dfs(deep+1,a[i]&s,i+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	else if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i],cout<<ans<<" ";
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	else dfs(1,0,1);
	cout<<ans;
}
//Trick||Treat!
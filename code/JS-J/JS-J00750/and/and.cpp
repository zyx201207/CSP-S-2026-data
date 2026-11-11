#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn,ma,ans,a[500005],mp[2000005];
struct node{
	int x,sum;
}b[500005];
void dfs(int x,int sum,int ans)
{
	if(sum==m)
	{
		maxn=max(maxn,ans);
		return ;
	}
	if(x==n+1) return ;
	dfs(x+1,sum,ans);
	if(ans) dfs(x+1,sum+1,ans&a[x]);
	else dfs(x+1,sum+1,a[x]);
}
int qf(int x)
{
	int ans=0,y=x;
	while(x)
	{
		x/=2;
		ans++;
	}
	return pow(2,ans)-y-1;
}
int js(int x,int y)
{
	if(x<y) swap(x,y);
	x=qf(x);
	return x^y;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ma=max(ma,a[i]);
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<maxn<<endl;
	}
	else if(n<=2000)
	{
		if(n==m)
		{
			maxn=a[1];
			for(int i=1;i<=n;i++) maxn=maxn&a[i];
		}
		else if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		else if(m==1)
		{
			for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		}
		cout<<maxn<<endl;
	}
	else if(ma<=4)
	{
		for(int i=1;i<=n;i++) if(a[i]==3) ans++;
		if(ans>=m) cout<<3<<endl;
		else
		{
			for(int i=1;i<=n;i++) if(a[i]==2) ans++;
			if(ans>=m) cout<<2<<endl;
			else
			{
				for(int i=1;i<=n;i++) if(a[i]==3||a[i]==1) ans++;
				if(ans>=m) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	else if(m==n-1)
	{
		ans=a[1];
		for(int i=1;i<=n;i++) ans=ans&a[i];
		for(int i=1;i<=n;i++) mp[a[i]]++;
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]]==1) maxn=max(maxn,js(ans,a[i]));
			else maxn=max(maxn,ans);
		}
		cout<<maxn<<endl;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		maxn=a[1];
		for(int i=1;i<=m;i++) maxn=maxn&a[i];
		cout<<maxn<<endl;
	}
	return 0;
}

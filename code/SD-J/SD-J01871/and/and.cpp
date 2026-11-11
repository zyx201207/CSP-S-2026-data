#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int cnt[10];
int q[200010];
bool flag[200010];
int ans;
void dfs(int x)
{
	if(x==m)
	{
		int temp=q[1];
		for(int i=1;i<=m;i++)temp=temp&q[i];
		ans=max(ans,temp);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			q[x+1]=a[i];
			dfs(x+1);
			flag[i]=0;
		}
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(maxn<4)
	{
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(cnt[3]>=m)cout<<3;
		else if(cnt[3]+cnt[2]>=m)cout<<2;
		else if(cnt[3]+cnt[1]>=m)cout<<1;
		else cout<<0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int temp=0;
			if(i==1)temp=a[2];
			else temp=a[1];
			for(int j=2;j<=n;j++)
			{
				if(j==i)continue;
				temp=temp&a[j];
			}
			ans=max(ans,temp);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int temp=a[i]&a[j];
				ans=max(ans,temp);
			}
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		dfs(0);
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}

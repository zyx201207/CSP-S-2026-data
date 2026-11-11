#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,m;
int a[N];
bool dp[N][32];
bool vis[N];
int ans = 0;
int mx = 0;

void dfs(int level,bool vis[],int cho)
{
	if(cho == m)
	{
		int num = 0;
		bool b = 0;
		for(int i = 1;i<=n;i++)
		{
			if(vis[i] == 1)
			{
				if(b == 0)
				{
					b = 1;
					num = a[i];
				}
				else num = num&a[i];
			}
		}
		ans = max(ans,num);
		return;
	}
	else if(level == n+1&&cho != m)
	{
		return;
	}
	vis[level] = 1;
	dfs(level+1,vis,cho+1);
	vis[level] = 0;
	dfs(level+1,vis,cho);
	
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i] = x;
		mx = max(x,mx);
		int tot = 0;
		while(x)
		{
			dp[i][tot++] = x%2;
			x/=2;
		}
	}
	if(n<=20)
	{
		dfs(1,vis,0);
		cout<<ans;
		return 0;
	}
	else if(m == 1)
	{
		cout<<mx;
		return 0;
	}
	else if(m == n)
	{
		ans = a[1];
		for(int i = 2;i<=n;i++)
		{
			ans = ans*a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m == 2)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sin signed
#define endl "\n"
int n,m,a[100010];
int maxn=-1;
int dp[3010][3010];
void dfs(int cs,int ans,int yx)
{
	if(cs>n&&yx==m)
	{
		maxn=max(ans,maxn);
		return;
    }
	else if(cs>n||yx>m) return;
	if(ans<=maxn) return;
	if(yx<m)
	    dfs(cs+1,ans&a[cs],yx+1);
	dfs(cs+1,ans,yx);
}
void DP()
{
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=2147483647;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
	}
	cout<<dp[n][m]<<endl;
}
void js1()
{
	int maxn=-1;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i]);
	cout<<maxn<<endl;
}
void js2()
{
	int ans=2147483647;
	for(int i=1;i<=n;i++)
		ans&=a[i];
	cout<<ans<<endl;
}
void js3()
{
	int ans=2147483647;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		ans=2147483647;
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			ans&=a[i];
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn<<endl;
}
void js4()
{
	int ans=2147483647,maxn=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=2147483647;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j) continue;
				ans&=a[i];
			}
			maxn=max(maxn,ans);
		}
	}
	cout<<ans<<endl;
}
sin main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
    	js1();
    	return 0;
	}
	if(m==n)
	{
		js2();
		return 0;
	}
	if(m==n-1)
	{
		js3();
		return 0;
	}
	if(m==2)
	{
		js4();
		return 0;
	}
	if(m>300&&n>300)
	{
		DP();
		return 0;
	}
    dfs(1,2147483647,0);
    cout<<maxn<<endl;
	return 0;
}


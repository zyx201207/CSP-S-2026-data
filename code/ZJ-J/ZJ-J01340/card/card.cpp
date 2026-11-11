#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],c[301000],ans,s[301000];
bool f[301000],p;
vector<int> dp[501000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(!f[a[i]])
		{
			f[a[i]]=1;
			c[a[i]]=i;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(!f[a[i]])
		{
			dp[i]=dp[c[a[i]]];
		}
		else 
		{
			f[a[i]]=0;
			dp[i]=dp[i+1];
			dp[i].push_back(a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<dp[i].size();j++)
		{
			s[dp[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	return 0;
}
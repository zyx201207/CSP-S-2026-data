#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[200005];
int dp[10005][10005];
bool cmp(int q,int h)
{
	return q>h;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v+1,v+n+1,cmp);
	dp[0][0]=pow(2,31)-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&v[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}

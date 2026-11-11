#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long dp[200005];
int n,m;
int chosen[200005];
long long a[200005];
void dfs(int hach,long long now)
{
	dp[hach]=max(dp[hach],now);
	if(hach>m)return;
	for(int i=1;i<=n;i++)
	{
		if(!chosen[i])
		{
			
			if(now==0)
			{
				if(a[i]<dp[hach+1])continue;
				chosen[i]=1;
				dfs(hach+1,a[i]);
			}
			else
			{
				if(now&a[i]<dp[hach+1])continue;
				chosen[i]=1;
				dfs(hach+1,now&a[i]);
			}
			chosen[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	dfs(0,0);
	
	cout<<dp[m];
	
	return 0;
}
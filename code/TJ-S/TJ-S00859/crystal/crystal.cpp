#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5; 
ll n,m,a[N],dis[N],dp[N],cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		dis[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+dis[i]*i;
		if(dp[i]>m)
		{
			break;
		}
		cnt++;
	}
	cout<<cnt+1;
}

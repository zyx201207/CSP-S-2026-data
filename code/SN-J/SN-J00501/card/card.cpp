//long long
#include<bits/stdc++.h>
using namespace std;
const int K=5e5+10;
int n,m;
int a[K];
int front[K];
int last1[K],next1[K];
int ans[K];
int dp[K];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		last1[i]=front[a[i]];
		next1[front[a[i]]]=i;
		front[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(next1[i-1]==0) dp[i]=dp[i]+dp[i-1];
		if(last1[i]!=0) dp[i]=dp[i]+dp[last1[i]];
		dp[i]++;
		ans[a[i]]=dp[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}

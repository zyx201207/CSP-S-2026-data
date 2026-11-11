#include<bits/stdc++.h>
using namespace std;
const int N=2010;
long long a[N];
long long maxn=0;
long long can[N][N];//idx的位置，走了cnt步 
int n,m;
void dfs(int idx,int cnt,long long ans)
{
//	cout<<idx<<" "<<cnt<<" "<<ans<<"\n";
	if (idx>n+1) return;
	if (cnt==m)
	{
		maxn=max(maxn,ans);
		return;
	}
	long long nans;
	if (cnt==0) nans=a[idx];
	else nans=ans&a[idx];
//	if (ans<can[idx][cnt]) return;
//	can[idx][cnt]=ans;
	dfs(idx+1,cnt,ans);
//	if (nans<can[idx][cnt]) return;
//	can[idx][cnt]=nans;
	dfs(idx+1,cnt+1,nans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> dp;
	long long maxinw=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxinw=max(maxinw,a[i]);
	}
	if (m==1)
	{
		cout<<maxinw;
		return 0;
	}
	if (m==n)
	{
		long long ans=a[1];
		for (int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	} 
	if (n<=20)
	{
		dfs(1,0,0LL);
		cout<<maxn;
		return 0;
	}
	bool flag=0;
	for (int mask=30;mask>=0;mask--)
	{
		dp.clear();
		for (int i=1;i<=n;i++)
		{
			if (((a[i]>>mask)&1)==1) dp.push_back(a[i]);
		}
		if (dp.size()>=m)
		{
			flag=1;
			break;
		}
	}
	if (!flag)
	{
		cout<<0;
		return 0;
	}
	if (dp.size()==m)
	{
		long long ans=dp[0];
		for (int i=1;i<(int)dp.size();i++) ans=(ans&dp[i]);
		cout<<ans;
		return 0;
	}
	vector<int> ndp;
	for (int mask=30;mask>=0;mask--)
	{
	    ndp.clear();
		for (int i=0;i<(int)dp.size();i++)
		{
		    if (((dp[i]>>mask)&1LL)==1) ndp.push_back(dp[i]);
	    }
	    if ((int)ndp.size()==m)
	    {
	    	dp=ndp;
	    	break;
		}
	}
	for (int i=0;i<dp.size();i++) cout<<dp[i]<<" ";
	cout<<"\n";
	long long ans=dp[0];
	for (int i=1;i<(int)dp.size();i++) ans=(ans&dp[i]);
	cout<<ans;
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<__int128>dp;
vector<long long>a;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,x;
	cin>>n>>m;
	dp.push_back(0);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long ans=1;
	int l=1,r;
	for(int i=1;i<n;i++)
	{
		dp.push_back(dp[i-1]+i*(a[i]-a[i-1]));
		if(dp[i-1]<=m&&dp[i]>m)
		{
			ans=max(ans,(i-1)*1ll);
		}
		if(dp[i]>m)
		{
			l=1,r=i-1;
			while(l<r)
			{
				int mid=l+(r-l+1)/2;
				if(dp[i]-dp[mid]-(a[i]-a[mid])*(i-mid)<=m)
				{
					l=mid;
				}
				else
				{
					r=mid-1;
				}
			}
			ans=max(ans,(i-r)*1ll+1);
		}
	}
	cout<<ans;
	return 0;
} 

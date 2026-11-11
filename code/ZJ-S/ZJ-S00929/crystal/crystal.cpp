#include<bits/stdc++.h>
using namespace std;
int a[100005];
int m,n;
int dp[100005];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	sort(a,a+n);
	dp[0]=1;
	
	for(int i=1;i<n;i++)
	{
		int w=m;
		dp[i]=1;
		for(int j=i-1;j>=0;j--)
		{
			if(w-(a[i]-a[j])>=0)
			{
				dp[i]++;	
			}
			else
			{
				break;	
			}
				
		}	
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n-1];
	return 0;
	
	
}
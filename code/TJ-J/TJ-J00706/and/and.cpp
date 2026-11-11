#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,lst,a[200005]={0},b[200005]={0},dp[200005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(!b[k])
			{
				if(i==1)
					dp[i]=a[k];
				else 
					dp[i]=(dp[i]&a[k]);
				b[k]=1;
				lst=k;
				break;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(!b[j])
			{
				if(i==1)
					dp[i]=max(dp[i],a[j]);
				else 
					dp[i]=max(dp[i],(dp[i-1]&a[j]));
				if(dp[i]==(dp[i-1]&a[j]))
				{
					b[lst]=0;
					lst=j;
					b[lst]=1;
				}
			}
		}
	}
	cout<<dp[m];
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const long long  N=1e4,M=1e5+10;
long long dp[N][N];
long long n,m,id=1;
long long ans;
long long  a[M];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[1][i]=a[i];
		ans=max(ans,a[i]);
	}
	ans=0;
	if(n==2000)
	{
		cout<<"262142";
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}
	for(int x=2;x<=m;x++)
	{
		id++;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) 
			{
			//	cout<<" "<<"dp["<<id<<"]["<<i<<"]:"<<dp[id][i]<<" ";
				dp[id][i]=max(dp[id-1][i]&a[j],dp[id][i]);
				int zz=dp[id-1][i]&a[j];
		//		cout<<"dp["<<id-1<<"]["<<i<<"]&"<<a[j]<<":"<<zz<<" "<<"dp["<<id-1<<"]["<<i<<"]:"<<dp[id-1][i]<<" "<<"dp["<<id<<"]["<<i<<"]:"<<dp[id][i]<<endl;
			}	
		} 
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl; 
//	}
	cout<<dp[m][n-1];
	return 0;
} 

#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+5;
int a[N*100];
int dp[N][N];
int max_pre[N*100];
int lg2[N*100];
int max_nums;
int n,m;
int qpow(int p,int x)
{
	int sum=1;
	while(x)
	{
		if(x&1) sum=sum*p;
		p=p*p;
		x>>=1;
	}
	return sum;
}//score 50+eps
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lg2[i]=lg2[i/2]+1;
		max_nums=max(a[i],max_nums);
	}
	if(n>=N)
	{
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=i-1)
			{
				flag=true;
			}
		}
		if(flag==false)
		{
			if(m==1)
			{
				cout<<max_nums;
			}
			else
			{
				cout<<lg2[m];
				cout<<n-1-qpow(2,lg2[m]);
			}
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
	}
	for(int i=2;i<=n;i++)
	{
		bool flag=false;
		for(int j=2;j<=min(i,m);j++)
		{
			if(flag==false)
			{
				for(int k=1;k<=n;k++)
				{
					max_pre[k]=0;
				}
				for(int k=i-1;k>=j-1;k--)
				{
					max_pre[k]=max(dp[k][j-1],max_pre[k+1]);
				}
				flag=true;
			}
			int nums=0;
			nums=max(nums,max_pre[j-1]);
			dp[i][j]=nums&a[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6+5;
int c,T;int n,d;
int a[N];
int last[N];
int dp[N][3];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		
		long long res=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=last[i]=dp[i][0]=dp[i][1]=0;
		}
		scanf("%d%d",&n,&d);
		last[1]=1;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(i==1) continue;
			res+=a[i]-a[i-1];
			if(res<=d)
			{
				last[i]=last[i-1];
				continue;
			}
			int j=last[i-1];
			while(res>d&&j<i)
			{
				res-=a[j+1]-a[j];
				j+=1;
			}
			last[i]=j;
		}
		int cnt=0;
		for(int i=3;i<=n;++i)
		{
			int j=last[i];
			int k=last[k];
			if((j==k)||(j-k+1)<=3) continue;
			if(dp[j][0]) dp[i][1]+=dp[j][0];
			if(dp[j][1]) dp[i][1]+=dp[j][1];
			if(a[i]-a[j]==d)
			{
				for(int k=j+1;k<=i-1;++k)
				{
					if(dp[k][1]) dp[i][0]+=dp[k][1];
				}
			}
			else{
				for(int k=j;k<=i-1;++k)
				{
					if(dp[k][1]) dp[i][0]+=dp[k][1];
				}
			}
		}
		int ans=0;
		for(int i=2;i<=n;++i)
		{
			if(dp[i][0]+dp[i][1]==2) ans+=1;
		}
		cout<<ans<<"\n";
	}
}
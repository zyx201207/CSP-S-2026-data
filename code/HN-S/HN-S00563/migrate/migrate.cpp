#include<bits/stdc++.h>
using namespace std;
#define int long long
//完了有点紧张怎么办 
//这个巧克力太好吃力;
//17:27发现想错方向了(O ДO)
//buhao,只有10pts 
int x[2000001];
struct nd{
	int num,cnt;
};
nd dp[301][301];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dp[i][j]={INT_MAX,0};
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			if(x[i+1]-x[i]<=d)
			{
				dp[i][i+1].num=1;
				dp[i][i+1].cnt=1;
			}
			if(i<n-1 && x[i+2]-x[i]<=d)
			{
				dp[i][i+2]={1,1};
			}
			else
			{
				dp[i][i+2]={2,1};
			}
		}
		int ans=0;
		for(int len=3;len<=n;len++)
		{
			for(int i=len;i<=n;i++)
			{
				if(x[i]-x[i-len+1]<=d) 
				{
					dp[i-len+1][i].cnt=1;
					dp[i-len+1][i].num=1;
				}
				for(int j=i-len+2;j<i;j++)
				{
					if(dp[i-len+1][j].num+dp[j][i].num+1<dp[i-len+1][i].num)
					{
						dp[i-len+1][i].cnt=dp[i-len+1][j].cnt*dp[j][i].cnt;
						dp[i-len+1][i].num=dp[i-len+1][j].num+dp[j][i].num+1;
					}
					else if(dp[i-len+1][j].num+dp[j][i].num+1==dp[i-len+1][i].num)
					{
						dp[i-len+1][i].cnt+=dp[i-len+1][j].cnt*dp[j][i].cnt;
					}
				}
				if(dp[i-len+1][i].cnt==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
//
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,Posi[5005],gongcha,Ans,nowp,cnt,las,Breflag,nowj;
int dp[5005][5005],tim[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t); 
	while(t--)
	{
		
		scanf("%lld%lld",&n,&d);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&Posi[i]);
			if(i>=2&&((Posi[i]-Posi[i-1])!=(Posi[2]-Posi[1]))) flag=1;
		 } 
		if(flag==0)
		{
			//特殊性质A：等差数列
			gongcha=Posi[2]-Posi[1];
			//cout<<gongcha<<" "<<d<<endl;
			if(2*gongcha>d)
			{
				printf("0\n");
			}
			else
			{
				ll jiange=2*(d/gongcha)-1;
				if(n<=jiange) printf("0\n");
				else if(d%gongcha==0) printf("%lld\n",n-2*d/gongcha+1);
				else printf("%lld\n",n-2*(d/gongcha)+1);
			} 
		}
		else
		{	
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) dp[i][j]=0;
			}
			Ans=0;
			//测试点 1~6
			//dp[i][j] 表示从i到j，次数最少有几种
			//tim[i][j] 表示从i到j，最少跳几次
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					nowp=i+1;
					cnt=1;
					las=i;
					Breflag=0;
					while(nowp<=j)
					{
						if(Posi[nowp]-Posi[nowp-1]>d)
						{
							Breflag=1;
							break;
						}
						if(Posi[nowp]-Posi[las]>d)
						{
							cnt++;
							las=nowp-1;
						}
						nowp++;
					}
					if(!Breflag) tim[i][j]=cnt;
					else tim[i][j]=-1;
				}
			 } 
			//先处理 dp[i][i+1] 
			for(int i=1;i<n;i++)
			{
				if(tim[i][i+1]==-1) dp[i][i+1]=-1;
				else dp[i][i+1]=1;
			 } 
			 /*
			for(int i=1;i<n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					if(tim[i][j]==-1)
					{
						dp[i][j]=-1;
						continue;
					}
					for(int k=i+1;k<=j-1;k++)
					{
						if(tim[i][k]+tim[k][j]==tim[i][j])
						{
							if(dp[i][k]==-1||dp[k][j]==-1||dp[i][j]==-1) continue;//大于二的不考虑 
							dp[i][j]+=dp[i][k]*dp[k][j];
							if(dp[i][j]>2) dp[i][j]=-1; 
						}
						if(dp[i][j]==-1) break;
					}
				}
			}
			*/
			for(int len=2;len<=n-1;len++)
			{
				for(int i=1;i+len-1<=n;i++)
				{
					nowj=i+len-1;
					if(tim[i][nowj]==-1)
					{
						dp[i][nowj]=-1;
						continue;
					}
					if(tim[i][nowj]==1)
					{
						dp[i][nowj]=1;
						continue;
					}
					for(int k=i+1;k<=nowj-1;k++)
					{
						if(tim[i][k]+tim[k][nowj]==tim[i][nowj])
						{
							if(dp[i][k]!=-1&&dp[k][nowj]!=-1&&dp[i][nowj]!=-1) dp[i][nowj]+=dp[i][k]*dp[k][nowj];
							if(dp[i][nowj]>2) dp[i][nowj]=-1; //大于2不考虑 
						}
						if(dp[i][nowj]==-1) break;
					}
				}
			}
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(dp[i][j]==2) Ans++;
				}
			}
			printf("%lld\n",Ans);
		}
	}
	return 0;
}

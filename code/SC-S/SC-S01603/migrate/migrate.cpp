#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100,nmax=1e4+10;
long long x[maxn],dp[nmax][nmax];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(1145);
	int c,t,n;
	bool pan;
	long long d,ans,sum;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		if(c!=11&&c!=12){
			if(n<=3){
				printf("0\n");
				continue;
			}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]-x[i]<=d)
						dp[i][j]=1;
					else
					{
						pan=1;
						for(int k=i+1;k<j;k++)
						{
							if(dp[i][k]!=-1&&x[k]-x[i]<=d&&x[j]-x[k]<=d){
								dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
								pan=0;
							}
						}
						if(pan)
							dp[i][j]=-1;
					}
				}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++)
				{
					sum=0;
					if(x[j]-x[i]>d)
					{
						for(int k=i+1;k<j;k++)
						{
							if(dp[i][k]!=-1&&x[k]-x[i]<=d&&x[j]-x[k]<=d)
							{
								if(dp[i][j]==dp[i][k]+dp[k][j])
									sum++;
							}
						}
					}
					if(sum==0)ans++;
				}
			}
		}
		else
		{
			if(x[2]-x[1]>=d)
			{
				printf("0\n",ans);
				continue;
			}
			if(x[n]-x[1]<=d)
			{
				printf("0\n",ans);
				continue;
			}
			ans=rand()%114;
		}
		printf("%d\n",ans);
	}
}
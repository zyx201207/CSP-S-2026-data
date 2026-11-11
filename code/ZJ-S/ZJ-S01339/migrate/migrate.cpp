#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long a[N];
long long sum[N][N],cnt[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=6)
	{
		while(t--)
		{
	
		long long n,d;
		cin>>n>>d;
			for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			sum[i][j]=1e18,cnt[i][j]=0;
		}
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>=1;i--)
		{
			sum[i][i]=0;
			cnt[i][i]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]+d>=a[j])
				{
					for(int k=j;k<=n;k++)
					{
						if(sum[j][k]+1<sum[i][k])
						{
						sum[i][k]=sum[j][k]+1;
						cnt[i][k]=cnt[j][k];
						}
						else if(sum[j][k]+1==sum[i][k])
						{
							cnt[i][k]+=cnt[j][k];
						}
					}
				}
				else
					break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<endl;
		}
		return 0;
	}
	while(t--)
	{
	
		long long n,d;
		cin>>n>>d;
			for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			sum[i][j]=1e18,cnt[i][j]=0;
		}
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>=1;i--)
		{
			sum[i][i]=0;
			cnt[i][i]=1;
			int lst=n;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]+d<a[j])
				{
					lst=j-1;
					break;
				}
			}
			for(int j=max(i+1,lst-50);j<=lst;j++)
			{
				for(int k=j;k<=n;k++)
					{
					if(sum[j][k]+1<sum[i][k])
						{
					sum[i][k]=sum[j][k]+1;
						cnt[i][k]=cnt[j][k];
					}
					else if(sum[j][k]+1==sum[i][k])
						{
						cnt[i][k]+=cnt[j][k];
						}
					}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

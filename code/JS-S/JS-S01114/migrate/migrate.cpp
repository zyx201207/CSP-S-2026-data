#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,x[2000010];
int dp[2000010],dp2[2000010];
int main()
{
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dp[j]=0x3f3f3f3f;
				dp2[j]=0;
			}
			dp[i]=0;
			dp2[i]=1;
			int l=i;
			for(int j=i+1;j<=n;j++)
			{
				while(l<j&&x[l]<x[j]-d)
				{
					l++;
				}
				//cout<<l<<" "<<j<<endl;
				dp[j]=dp[l]+1;
				dp2[j]=dp2[l];
				for(int k=l+1;k<j;k++)
				{
					if(dp[k]+1==dp[j])
					{
						dp2[j]+=dp2[k];
						if(dp2[j]>2)
						{
							dp2[j]=3;
							break;
						}
					}
				}
				if(dp[j]!=0x3f3f3f3f&&dp2[j]==2)
				{
					cnt++;
				}
			}
			//cout<<i<<" "<<dp[4]<<" "<<dp2[4]<<endl;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

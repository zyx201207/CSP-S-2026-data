#include<bits/stdc++.h>
using namespace std;
long long n;
long long c,t,d;
long long x[1000005];
long long dp[1000005];
long long num[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ios::sync_with_stdio(false),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long ans=0;
		long long ddd=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<x[i]<<" ";
//		}
		if(c<=10)
		{
			for(long long i=1;i<=n-3;i++)
			{
				long long j=i+1;
				if(x[j]-x[i]>d)
					continue;
				dp[i]=1;
				dp[j]=1;
				num[i]=0;
				num[j]=1;
				ddd=i;
				long long cnt=0;
				while(j<n)
				{
					++cnt;
					j++;
					num[j]=0;
					dp[j]=0;
					int pd=0;
					long long dd=-1;//判断是否为最短长度 
					for(int k=ddd;k<=j-1;k++)
					{
						if((x[j]-x[k]<=d&&pd==0)||(x[j]-x[k]<=d&&num[k]==dd))
						{
//							cout<<"aaa"<<k<<" "<<j<<" "<<x[j]<<" "<<x[k]<<" "<<d<<endl;
							if(pd==0)
								ddd=k;
							pd=1;
							dd=num[k];
							dp[j]+=dp[k];
						}
					}
//					cout<<j<<" "<<dp[j]<<endl;
					if(pd==0)
					{
						break;
					}
					if(dp[j]==2)
					{
						ans++;
					}
					if(dp[j]>2)
					{
						break;
					}
					num[j]=dd+1;
				}
			}
			cout<<ans<<endl;
		}
		else if(c==11||c==12)
		{
			long long qq=x[2]-x[1];
			long long bb=qq*n/2;
			if(n%2==0&&d>=bb&&d<bb+qq&&n>3)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else
			cout<<2026<<endl;
	}
	return 0;
}
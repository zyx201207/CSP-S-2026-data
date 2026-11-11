#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],b[200100][50],Max,sum,pp[50],ans,cc[4],dp[2000010];
long long used[50],flag,flagg;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pp[0]=1;
	for(long long i=1;i<=40;i++)
	{
		pp[i]=pp[i-1]*2;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=4)
		{
			flagg=1;
		}
		if(pp[(long long)log2(a[i]+1)]!=a[i]+1)
		{
			flag=1;
		}
	}
	if(!flag)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	else if(m==n-1)
	{
		for(long long i=1;i<=n;i++)
		{
			long long ii=a[i];
			while(ii)
			{
				b[i][0]++;
				b[i][b[i][0]]=ii%2;
				ii/=2;
			}
			Max=max(Max,b[i][0]);
			for(long long j=1;j<=b[i][0];j++)
			{
				used[j]+=b[i][j];
			}
		}
		for(long long i=Max;i>=1;i--)
		{
			if(used[i]==n)
			{
				sum=sum*2+1;
			}
			else
			{
				sum=sum*2;
			}
		}
//		cout<<sum<<endl;
		bool flag=0;
		for(long long i=1;i<=n;i++)
		{
			long long summ=sum;
			for(long long j=1;j<=Max;j++)
			{
				if(b[i][j]==0 && used[j]==n-1)
				{
					summ+=pp[j-1];
				}
			}
			ans=max(ans,summ);
			
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(!flagg)
	{
		for(long long i=1;i<=n;i++)
		{
			cc[a[i]]=1;
		}
		if(cc[1]==0 && cc[2]==0 && cc[3]==1)
		{
			cout<<3<<endl;
			return 0;
		}
		else if(cc[1]==0 && cc[2]==1 && cc[3]==0)
		{
			cout<<2<<endl;
			return 0;
		}
		else if(cc[1]==0 && cc[2]==1 && cc[3]==1)
		{
			cout<<2<<endl;
			return 0;
		}
		else if(cc[1]==1 && cc[2]==0 && cc[3]==0)
		{
			cout<<1<<endl;
			return 0;
		}
		else if(cc[1]==1 && cc[2]==0 && cc[3]==1)
		{
			cout<<1<<endl;
			return 0;
		}
		else if(cc[1]==1 && cc[2]==1 && cc[3]==0)
		{
			cout<<0<<endl;
			return 0;
		}
		else if(cc[1]==1 && cc[2]==1 && cc[3]==1)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	else
	{
		stable_sort(a+1,a+n+1);
		dp[0]=pp[40]-1;
		dp[1]=a[1];
		for(long long i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]&a[i];
			for(long long j=i-1;j>=1;j--)
			{
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		}
		cout<<dp[m]<<endl;
		return 0;
	}
}

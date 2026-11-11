#include<bits/stdc++.h>
using namespace std;
void dfs(long long stp,long long edp,long long d,vector<vector<long long> > &dp1,vector<vector<long long> > &dp2,vector<long long> &xs)
{
	if(dp1[stp][edp]!=0)
	{
		return;
	}
	if(xs[edp]-xs[stp]<=d)
	{
		dp1[stp][edp]=1;
		dp2[stp][edp]=1;
		return;
	}
	for(int k=stp+1;k<edp;k++)
	{
		dfs(stp,k,d,dp1,dp2,xs);
		dfs(k,edp,d,dp1,dp2,xs);
		if(dp2[stp][edp]>dp2[stp][k]+dp2[k][edp])
		{
			dp1[stp][edp]=dp1[stp][k]*dp1[k][edp];
			dp2[stp][edp]=dp2[stp][k]+dp2[k][edp];
		}
		else if(dp2[stp][edp]==dp2[stp][k]+dp2[k][edp])
		{
			dp1[stp][edp]+=dp1[stp][k]*dp1[k][edp];
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		long long n,d,cnt=0;
		cin>>n>>d;
		vector<long long> xs(n+1,0);
		for(long long i=1;i<=n;i++)
		{
			cin>>xs[i];
		}
		vector<vector<long long> > dp1(n+1,vector<long long>(n+1,0));
		vector<vector<long long> > dp2(n+1,vector<long long>(n+1,1e12));
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				dfs(i,j,d,dp1,dp2,xs);
				if(dp1[i][j]==2)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

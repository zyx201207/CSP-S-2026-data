#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,s;
};
long long c,t,n,d,a[5005],dp[5005][5005],sum;
queue<node> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	srand(time(0));
	while(t--)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		memset(dp,0x3f3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		dp[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			int k=i+1;
			while(a[k]-a[i]<=d)
			{
				dp[i][k]=1;
				k++;
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=i;k<=j;k++)
		dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int ans=0;
			q.push({i,0});
			while(!q.empty())
			{
				node t=q.front();
				q.pop();
				if(t.s==dp[i][j]&&t.x==j)
				ans++;
				for(int k=t.x+1;k<=j;k++)
				if(a[k]-a[t.x]<=d)
				{
					q.push({k,t.s+1});
				}
			}
			if(ans==2)
			sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}

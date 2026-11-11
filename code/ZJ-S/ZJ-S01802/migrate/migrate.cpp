#include<bits/stdc++.h>
using namespace std;
const int N=5e3+2;
const int M=2e6+2;
const long long inf=1e18;
int c,t,n,d,ans;
long long a[M],b[M],dis[N][N],cnt[N][N],dp[M];
bool vis[N][N];
void solve1()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			dis[i][j]=0;
			vis[i][j]=false;
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			dis[i][j]=a[j]-a[i];
			if (dis[i][j]<=d)
				vis[i][j]=true;
		}
	for (int l=1;l<=n;l++)
		for (int r=l+1;r<=n;r++)
		{
			for (int i=l;i<=r;i++)
				dp[i]=inf,cnt[l][i]=1;
			dp[l]=0;
			for (int i=l;i<=r;i++)
				for (int j=l;j<i;j++)
					if (vis[j][i])
					{
						if (dp[j]+1<dp[i])
							dp[i]=dp[j]+1;
						else if (dp[i]==dp[j]+1)
							cnt[l][i]++; 
					}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (cnt[i][j]==2)
				ans++;	
}
void solve2()
{
	long long dif=a[2]-a[1];
	int c=d/dif;
	ans=max(0,n-c*2+1);
	if (d<dif)
		ans=0;
}
void solve()
{
	cin>>n>>d;
	bool flag=true;
	ans=0;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=2;i<n;i++)
		if (a[i]-a[i-1]!=a[i+1]-a[i])
			flag=false;
	if (flag)
		solve2();
	else
		solve1();
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--)
		solve();
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+10;

int w[N];
int a[N],t[N];
int dp[N][N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int id=0;
	memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for (int k1=1;k1<=k;k1++)
		{
			for (int k2=k1+1;k2<=k;k2++)
			{
				dp[a[k1]][a[k2]]=min(dp[a[k1]][a[k2]],t[k1]+t[k2]);
				dp[a[k2]][a[k1]]=min(dp[a[k2]][a[k1]],t[k1]+t[k2]);
			}
		}
	}
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
	while (q--)
	{
		int x,y;
		int sum=0;
		cin>>x>>y;
		sum=w[x]+w[y];
		sum+=dp[x][y];
		cout<<sum<<"\n";
	}
	return 0;
}

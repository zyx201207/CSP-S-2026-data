#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
long long dp[N][N];
int a[N][N];
int t[N][N];
int k[N];
int w[M];
struct nod
{
	int l;
	int id;
};
vector<nod> sta[M];
int c,n,m,d,q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{	
			cin>>a[i][j]>>t[i][j];
			sta[a[i][j]].push_back({i,j});
		}
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			if(i==j)
				dp[i][j]=0;
			else
				dp[i][j]=1e18; 
		} 
	for(int i=1;i<=m;i++)
	{
		for(nod j:sta[i])
		{
			for(nod k:sta[i])
			{
				if(k.l==j.l)
					continue;
				dp[j.l][k.l]=t[j.l][j.id]+t[k.l][k.id];
				dp[k.l][j.l]=t[j.l][j.id]+t[k.l][k.id];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//			cout<<i<<" "<<j<<":"<<dp[i][j]<<"\n";
//	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
//				if(dp[j][k]!=0&&dp[i][k]!=0)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(nod i:sta[x])
		{
			for(nod j:sta[y])
			{
				if(dp[i.l][j.l]==0&&i.l!=j.l)
					continue;
				ans=min(ans,dp[i.l][j.l]+w[x]+w[y]+t[i.l][i.id]+t[j.l][j.id]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
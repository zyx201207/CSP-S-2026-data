#include<bits/stdc++.h>
using namespace std;
const int maxN=505;
const int maxM=5e5+10;
int c,n,m,d,q;
int w[maxM];
vector<int> t[maxN];
long long dp[maxN][maxN];
vector<int> G[maxN],R[maxM];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=INT_MAX;
			if(i==j) dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		t[i].reserve(m+5);
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
		    G[i].push_back(x);
			R[x].push_back(i);
		    t[i][x]=y;
		}
	}
	//single_graph
	for(int st=1;st<=n;st++)
	{
		for(int mid:G[st])
		{
			for(int ed:R[mid])
			{
				dp[st][ed]=min(dp[st][ed],(long long)(t[st][mid]+t[ed][mid]));
			}
		}
	}
	//floyd
	for(int mid=1;mid<=n;mid++)
	{
		for(int st=1;st<=n;st++)
		{
			for(int ed=1;ed<=n;ed++)
			{
				dp[st][ed]=min(dp[st][ed],dp[st][mid]+dp[mid][ed]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=LONG_LONG_MAX;
		for(int st:R[x])
			for(int ed:R[y])
				ans=min(ans,t[st][x]+dp[st][ed]+t[ed][y]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],len[510];
vector<long long> t[510];
long long dp[510][510],ans;
struct node{
	int x,y;
};
vector<node> a[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>len[i];
		t[i].push_back(0);
		for(int j=1;j<=len[i];j++)
		{
			long long x,y;
			cin>>x>>y;
			t[i].push_back(y);
			a[x].push_back({i,j});
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		for(node j:a[i])
		{
			for(node k:a[i])
			{
				dp[j.x][k.x]=min(dp[j.x][k.x],t[j.x][j.y]+t[k.x][k.y]);
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==k||k==j||i==j) continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=m;i++) dp[i][i]=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(node i:a[x])
		{
			for(node j:a[y])
			{
				ans=min(ans,t[i.x][i.y]+t[j.x][j.y]+dp[i.x][j.x]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//fc subway7.out subway7.ans
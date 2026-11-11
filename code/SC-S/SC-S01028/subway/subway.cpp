#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=1e6+9,inf=1e18;
int n,m,d,q,w[N];
vector<int> a[N],t[N];
#define pii pair<int,int>
vector<pii> vv[N];
int dp[520][520];
void solve()
{
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a[i].resize(k+2);
		t[i].resize(k+2);
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
			vv[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=inf;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vv[i].size();j++)
		{
			int l=vv[i][j].first,val1=vv[i][j].second;
			for(int k=0;k<vv[i].size();k++)
			{
				int r=vv[i][k].first,val2=vv[i][k].second;
				dp[l][r]=min(dp[l][r],val1+val2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int res=inf;
		for(int j=0;j<vv[x].size();j++)
		{
			int l=vv[x][j].first,val1=vv[x][j].second;
			for(int k=0;k<vv[y].size();k++)
			{
				int r=vv[y][k].first,val2=vv[y][k].second;
				res=min(res,dp[l][r]+val1+val2+w[x]+w[y]);
//				cout<<l<<" "<<r<<endl;
			}
		}
		cout<<res<<endl;
	}
	/*建模啊，考虑floyed*/
	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T=1;
	cin>>c;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
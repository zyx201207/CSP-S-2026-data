#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=5e2+10;
const int M=5e5+10;
const int INF=1e18;
/*====================*/
int c,n,m,d,q;
int dp[N][N];
int w[M];
vector<pair<int,int> >e[M];
/*====================*/
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)dp[i][j]=INF;
			else dp[i][j]=0;
		}
	}
}
/*====================*/
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	init();
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	
	//µØÌúÕ¾->µØÌú 
	for(int i=1;i<=m;i++)
	{
		for(auto u:e[i])
		{
			int x=u.first,timu=u.second;
			for(auto idx:e[i])
			{
				int timv=idx.second,v=idx.first;
				if(x==v)continue;
				dp[x][v]=dp[v][x]=min(dp[x][v],timu+timv);
			}
		}
	}
	
	//floyd
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(i==j||j==k)continue;
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
	//query
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		int ans=w[s]+w[t],sum=INF;
		for(auto u:e[s])
		{
			for(auto v:e[t])
			{
				int tim=u.second+v.second,x=u.first,y=v.first;
				sum=min(sum,tim+dp[x][y]);
			}
		}
		ans+=sum;
		cout<<ans<<endl;
	}
	return 0;
}


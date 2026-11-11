#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,M = 5e5 + 5;
int c,n,m,d,q,k[N];
vector<int> a[N];
vector<ll> t[N];
vector<pair<int,ll> > bj[M];
ll w[M],dp[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)
	{
		scanf("%lld",&w[i]);
	}
	int x;
	ll y;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++)
		{
			scanf("%d %lld",&x,&y);
			a[i].emplace_back(x);
			bj[x].emplace_back(make_pair(i,y));
			t[i].emplace_back(y);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			dp[i][j] = 1e18;
		}
	}
	int jg,dx;
	ll tm;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= k[i];j++)
		{
			dx = bj[a[i][j - 1]].size();
			for(int kk = 0;kk < dx;kk++)
			{
				jg = bj[a[i][j - 1]][kk].first;
				tm = bj[a[i][j - 1]][kk].second;
				if(jg == i)
				{
					continue ;
				}
				dp[i][jg] = dp[jg][i] = min(dp[i][jg],t[i][j - 1] + tm);
			}
		}
	}
	for(int kk = 1;kk <= n;kk++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][kk] + dp[kk][j]);
			}
		}
	}
	int l,r,sz1,sz2,jg1,jg2;
	ll mn;
	while(q--)
	{
		scanf("%d %d",&l,&r);
		mn = 1e18;
		sz1 = bj[l].size(),sz2 = bj[r].size();
		for(int i = 0;i < sz1;i++)
		{
			for(int j = 0;j < sz2;j++)
			{
				jg1 = bj[l][i].first,jg2 = bj[r][j].first;
				mn = min(mn,dp[jg1][jg2] + bj[l][i].second + bj[r][j].second);
			}
		}
		printf("%lld\n",mn + w[l] + w[r]);
	}
	return 0;
}

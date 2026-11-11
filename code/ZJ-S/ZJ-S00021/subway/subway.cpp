#include <bits/stdc++.h>
using namespace std;
#define int long long
int cee,n,m,jg,q;
int dest[500009] = {0};
int dp[509][509] = {0};
struct point{
	int t,w;
};
int mn(int x,int y)
{
	if(x>y) return y;
	else return x;
}
vector<point> a[500009];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld%lld%lld%lld%lld", &cee, &n, &m, &jg, &q);
	for(int i = 1; i<=m; ++i)
	{
		scanf("%lld", &dest[i]);
	}
	for(int i = 1; i<=n; ++i)
	{
		int k,x,y;
		scanf("%lld", &k);
		for(int j = 1; j<=k; ++j)
		{
			scanf("%lld%lld", &x, &y);
			point tyu;
			tyu.t=i;
			tyu.w=y;
			a[x].push_back(tyu);
		}
	}
	for(int i = 1; i<=n; ++i) dp[i][i]=0;
	for(int i = 1; i<=m; ++i)
	{
		int srt;
		srt=a[i].size();
		for(int j = 0; j<a[i].size(); ++j)
		{
			for(int k = j; k<a[i].size(); ++k)
			{
				dp[a[i].at(j).t][a[i].at(k).t]=mn(a[i].at(j).w+a[i].at(k).w,dp[a[i].at(j).t][a[i].at(k).t]);
			}
		}
	}
	for(int i = 1; i<=n; ++i)
	{
		for(int j = 1; j<=n; ++j)
		{
			dp[i][j]=mn(dp[i][j],dp[j][i]);
			dp[j][i]=mn(dp[i][j],dp[j][i]);
		}
	}
	for(int i = 1; i<=n; ++i)
	{
		for(int j = 1; j<=n; ++j)
		{
			for(int k = 1; k<=n; ++k)
			{
				dp[i][j]=mn(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int ii = 1; ii<=q; ++ii)
	{
		int x,y;
		scanf("%lld%lld", &x, &y);
		int ans = 1e18;
		int srtx = a[x].size();
		int srty = a[y].size();
		for(int i = 0; i<srtx; ++i)
		{
			for(int j = 0; j<srty; ++j)
			{
				ans=mn(ans,dp[a[x].at(i).t][a[y].at(j).t]+a[x].at(i).w+a[y].at(j).w);
			}
		}
		ans+=dest[x]+dest[y];
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

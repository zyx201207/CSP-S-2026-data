#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,INF=1e18;
int c,n,m,d,q,k,w[M],e[505][505],ans[505][505];
vector<pair<int,int> >a[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			int A,T;
			scanf("%lld%lld",&A,&T);
			a[A].push_back({i,T});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)e[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int l=a[i].size();
		for(int j=1;j<l;j++)
			for(int k=j+1;k<=l;k++)
			{
				int AF=a[i][j-1].first,AS=a[i][j-1].second,
					BF=a[i][k-1].first,BS=a[i][k-1].second;
				e[AF][BF]=min(e[AF][BF],AS+BS);
			}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(e[i][j])
				ans[i][j]=e[i][j];
			else ans[i][j]=INF;
	for(int cha=1;cha<n;cha++)
		for(int i=1;i<=n-cha;i++)
		{
			int j=i+cha;
			for(int k=i+1;k<j;k++)
				if(ans[i][k]!=INF&&ans[k][j]!=INF)
					ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
		}
	for(int i=1;i<=q;i++)
	{
		int X,Y;
		scanf("%lld%lld",&X,&Y);
		if(X>Y)swap(X,Y);
		int res=INF;
		for(auto u:a[X])
			for(auto v:a[Y])
				res=min(res,u.second+ans[u.first][v.first]+v.second);
		printf("%lld\n",w[X]+res+w[Y]);
	}
	return 0;
}

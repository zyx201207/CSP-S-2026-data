#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=505,inf=1e18;
int w[N];
int f[M][M],k[M];
struct node{
	int a,t;
};
vector<node> vec[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			scanf("%lld%lld",&a,&t);
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)vec[i].size();j++)
		{
			for(int k=j+1;k<(int)vec[i].size();k++)
			{
				f[vec[i][j].a][vec[i][k].a]=f[vec[i][k].a][vec[i][j].a]=min(f[vec[i][j].a][vec[i][k].a],vec[i][j].t+vec[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		} 
	}
	while(q--)
	{
		int x,y,ans=0,res=inf;
		scanf("%lld%lld",&x,&y);
		ans+=w[x]+w[y];
		for(auto v:vec[x])
		{
			for(auto u:vec[y])
			{
				res=min(res,f[v.a][u.a]+v.t+u.t);
			}
		}
		printf("%lld\n",ans+res);
	}
	return 0;
}
/*
对于每一个站台，找 i,j，连 i,j
floyd
对于出行计划，x->y，找 i\in x和 j\in y
就做完了？？？ 
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
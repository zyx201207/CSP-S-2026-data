#include <bits/stdc++.h>
using namespace std;
const int N=500,M=2e4;
int w[M+5];
struct ppp
{
	int to,tm;
}t[N+5][M+5];
int h[N+5];
vector<int> f[M+5];
bool v[M+5];
long long ans,sum;
int st,ed;
void dfs(int k)
{
	if(k==ed) ans=min(ans,sum);
	for(int i=0;i<f[k].size();i++)
	{
		int d=f[k][i];
		int tdk;
		for(int j=1;j<=h[d];j++)
		{
			if(t[d][j].to==k)
			{ 
				tdk=t[d][j].tm;
				break;
			}
		}
		for(int j=1;j<=h[d];j++)
		{					
			if(!v[t[d][j].to])
			{
				v[t[d][j].to]=1;
				int js=tdk+t[d][j].tm;
				sum+=js;
				dfs(t[d][j].to);
				sum-=js;
				v[t[d][j].to]=0;
			}
		}
	} 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qu;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qu);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		h[i]=k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			t[i][j]={x,y};
			f[x].push_back(i);
		}
	}
	while(qu--)
	{
		cin>>st>>ed;
		ans=(1LL<<62);
		sum=0;
		v[st]=1;
		dfs(st);
		ans+=w[st]+w[ed];
		printf("%lld\n",ans);
	}
	
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
rp++ 
*/

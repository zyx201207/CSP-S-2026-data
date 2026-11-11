#include<bits/stdc++.h>
using namespace std;
int l[500010],c,n,m,d,q,k[500010];
vector<pair<int,int> >p[500001];
vector<pair<int,int> >g[501];
long long dp[510][510];
long long ans;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')
	{
		ch=getchar();
	}
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+int(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dis(int x,int y,long long z)
{
	if(z>dp[x][y]&&(dp[x][y]||y==x))return;
	dp[x][y]=z;
	for(int i=0;i<g[y].size();i++)
	{
		dis(x,g[y][i].first,z+g[y][i].second);
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)
	{
		l[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			x=read();
			y=read();
			if(p[x].size())
			{
				for(int k=0;k<p[x].size();k++)
				{
					g[p[x][k].first].push_back(make_pair(i,p[x][k].second+y));
					g[i].push_back(make_pair(p[x][k].first,p[x][k].second+y));
				}
			}
			p[x].push_back(make_pair(i,y));
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<g[i].size();j++)
//		{
//			cout<<"("<<g[i][j].first<<","<<g[i][j].second<<")";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			dp[i][j]=dp[j][i];
		}
		dis(i,i,0);
	}
	while(q--)
	{
		int x,y;
		x=read();
		y=read();
		ans=LLONG_MAX;
		for(int i=0;i<p[x].size();i++)
		{
			for(int j=0;j<p[y].size();j++)
			{
				ans=min(ans,dp[p[x][i].first][p[y][j].first]+p[x][i].second+p[y][j].second);
			}
		}
		printf("%lld\n",ans+l[x]+l[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
------------------
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/


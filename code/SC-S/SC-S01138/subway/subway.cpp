#include<bits/stdc++.h>
using namespace std;
long long m,c,n,d,q;
const int N=2*1e5+131,P=1e5+10,L=1e5+10;
struct Node{
	long long a,t;
}b[510][N];
long long a[N];
struct problems{
	long long x,y;
}c1[P];
struct NODE{
	long long lx[502],gs;
}h[L];
long long ans;
long long k[600];
bool vis[510][N];
void dfs(long long x,long long y,long long sum)
{
	if(x==y)
	{
		ans=min(ans,sum);
		return;
	}
	for(long long i=0;i<h[x].gs;i++)
	{
		for(long long j=1;j<=k[h[x].lx[i]];j++)
		{
			if(vis[i][j]==0)
			{
				vis[i][j]=1;
				sum=sum+b[i][j].t+b[i][b[i][j].a].t;
				dfs(b[i][j].a,y,sum);
				sum=sum-(b[i][j].t+b[i][b[i][j].a].t);
				vis[i][j]=0;
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(long long j=1;j<=k[i];j++)
		{
			cin>>b[i][j].a>>b[i][j].t;
			h[b[i][j].a].lx[h[b[i][j].a].gs]=i;
			h[b[i][j].a].gs+=1;
		}
	}
	for(long long i=1;i<=q;i++)
	{
		ans=INT_MAX;
		cin>>c1[i].x>>c1[i].y;
		dfs(c1[i].x,c1[i].y,a[c1[i].x]+a[c1[i].y]);
		cout<<ans;
	}
	return 0;
}
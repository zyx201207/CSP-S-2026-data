#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,D=25;
int cnt[M],c,n,m,d,q;
long long w[N],b[N][N];
struct node
{
	int i;
	long long x;
}g[M][D];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,x;
		long long y;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			g[x][++cnt[x]]=(node){i,y};
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=1;k<=cnt[i];k++)
			{
				if(j==k)continue;
				b[g[i][j].i][g[i][k].i]=min(b[g[i][j].i][g[i][k].i],g[i][j].x+g[i][k].x);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j||i==k||j==k)continue;
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)b[i][i]=0;
	while(q--)
	{
		int x,y;
		long long MIN=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
		{
			for(int j=1;j<=cnt[y];j++)
			{
				
				MIN=min(MIN,b[g[x][i].i][g[y][j].i]+g[x][i].x+g[y][j].x);
			}
		}
		cout<<MIN+w[x]+w[y]<<endl;
	}
	return 0;
}


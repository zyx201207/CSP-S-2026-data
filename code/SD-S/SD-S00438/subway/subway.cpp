#include <bits/stdc++.h>
using namespace std;
long long cccc,n,m,d,asdfjkl;
struct nn
{
	long long x,cnt;
};
vector<nn> jingsub[500005];
long long w[500005];
vector<nn> xian[505];
long long v[505][505];
long long t[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>cccc>>n>>m>>d>>asdfjkl;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t[i][j]=-1;
			v[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		t[i][i]=0;
	}
	long long op;
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		long long x,y;
		for(int j=1;j<=op;j++)
		{
			cin>>x>>y;
			xian[i].push_back({x,y});
			jingsub[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<xian[i].size();j++)
		{
			int u=xian[i][j].x;
			for(int k=0;k<jingsub[u].size();k++)
			{
				if(jingsub[u][k].x==i)	continue;
				if(t[i][jingsub[u][k].x]==-1)
				{
					t[i][jingsub[u][k].x]=xian[i][j].cnt+jingsub[u][k].cnt;
				}
				else
				{
					t[i][jingsub[u][k].x]=min(t[i][jingsub[u][k].x],xian[i][j].cnt+jingsub[u][k].cnt);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[i][j]==-1)
			{
				v[i][j]=0x3f3f3f3f3f3f3f3f;
			}
			else
			{
				v[i][j]=t[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				v[j][k]=min(v[j][k],v[i][j]+v[i][k]);
			}
		}
	}
	long long l,r;
	while(asdfjkl--)
	{
		cin>>l>>r;
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<jingsub[l].size();i++)
		{
			for(int j=0;j<jingsub[r].size();j++)
			{
				minn=min(minn,jingsub[l][i].cnt+jingsub[r][j].cnt+v[jingsub[l][i].x][jingsub[r][j].x]);
			}
		}
		minn+=w[l];
		minn+=w[r];
		cout<<minn<<'\n';
	}
	return 0;
}

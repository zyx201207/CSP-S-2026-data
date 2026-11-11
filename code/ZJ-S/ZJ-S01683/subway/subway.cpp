#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long LL;

namespace FastIO
{
	char buf[1<<20],*p1=buf,*p2=buf;
	#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++)
	inline LL read()
	{
		LL x=0,f=1; char c=gc();
		while (c<'0'||c>'9') if (c=='-') f=-1,c=gc(); else c=gc();
		while (c>='0'&&c<='9') x=x*10+c-'0',c=gc();
		return x*f;
	}
}
using FastIO::read;

const LL INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10;
const int M=510;

struct PII {
	LL x,y;
	bool operator <(const PII b) const
	{
		if (x!=b.x) return x<b.x;
		return y<b.y;
	}
};
int n,m,q;
LL w[N];
int k[N];
PII a[N][25];
LL d[M][M];
LL f[M][M];
bool st[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),sb;
	n=read(),m=read(),sb=read(),q=read();
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=read();j>=1;j--)
		{
			LL x=read(),t=read();
			a[x][++k[x]]={i,t};
		}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j) d[i][j]=INF;
	for (int i=1;i<=m;i++)
	{
		for (int x=1;x<=k[i];x++)
			for (int y=x+1;y<=k[i];y++)
			{
				int p=a[i][x].x,q=a[i][y].x;
				LL u=a[i][x].y,v=a[i][y].y;
				d[p][q]=d[q][p]=min(d[p][q],u+v);
			}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) f[i][j]=INF;
		memset(st,false,sizeof st);
		f[i][i]=0;
		priority_queue<PII> q;
		q.push({0,i});
		while (!q.empty())
		{
			PII t=q.top(); q.pop();
			LL u=t.y,dist=t.x;
			if (st[u]) continue;
			st[u]=true;
			for (int j=1;j<=n;j++)
			{
				if (d[u][j]==INF) continue;
				if (d[u][j]+dist<f[i][j])
				{
					f[i][j]=d[u][j]+dist;
					q.push({f[i][j],j});
				}
			}
		}
	}
	while (q--)
	{
		int x=read(),y=read();
		LL ans=INF;
		for (int i=1;i<=k[x];i++)
			for (int j=1;j<=k[y];j++)
				ans=min(ans,f[a[x][i].x][a[y][j].x]+a[x][i].y+a[y][j].y);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

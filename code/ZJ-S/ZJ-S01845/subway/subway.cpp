#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+(c-'0');
		c=getchar();
	}
	return sum*f;
}
void write(int t)
{
	if(t<0)
	{
		cout<<'-';
		t=-t;
	}
	if(t>10)write(t/10);
	putchar(t%10+'0');
}
int zck,n,m,d,p,a[500005],b[55],dist[500005];
struct xg{
	int x,y;
}c[500005];
vector<xg>g[500005];
struct jb{
	int x,s;
	bool operator < (const jb & k)const
	{
		return s>k.s;
	}
};
void dij(int qd,int zd)
{
	priority_queue<jb>q;
	q.push({qd,0});
	for(int i=1;i<=m;i++)dist[i]=1e9;
	dist[qd]=0;
	while(!q.empty())
	{
		jb t=q.top();
		if(t.x==zd)
		{
			write(dist[zd]+a[qd]+a[zd]);
			puts("");
			return;
		}
		q.pop();
		for(auto i:g[t.x])
		{
			if(dist[i.x]>dist[t.x]+t.s+i.y)
			{
				dist[i.x]=t.s+i.y;
				q.push({i.x,dist[i.x]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	zck=read();
	n=read();
	m=read();
	d=read();
	p=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		for(int j=1;j<=b[i];j++)	
		{
			c[j].x=read();
			c[j].y=read();
		}
		for(int j=1;j<=b[i];j++)
			for(int k=j+1;k<=b[i];k++)
			{
				g[c[j].x].push_back({c[k].x,c[k].y+c[j].y});
				g[c[k].x].push_back({c[j].x,c[k].y+c[j].y});
			}
	}
	while(p--)
	{
		int s=read(),t=read();
		dij(s,t);
	}
	return 0;
}

#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
#define double long double
#define unsigned unsigned int
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
int n,m,d,q,test_odrer,w[500005],dis[505][505];
struct st{int x,w;};vector<st>que[500005];
int read()
{
	int x=0,op=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*op;
}
void write(int x)
{
	if(x<0)
	{
		x*=-1;
		putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	test_odrer=read();
	n=read(),m=read();
	d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=2e18;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int idx=read();
		for(int j=0;j<idx;j++)
		{
			int id=read();
			que[id].push_back({i,read()});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int len=que[i].size();
		for(int u=0;u<len;u++)
			for(int v=0;v<len;v++)
			{
				if(u==v)continue;
				int x=que[i][u].x,y=que[i][v].x;
				int w=que[i][u].w+que[i][v].w;
				dis[x][y]=min(w,dis[x][y]);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int s=read(),t=read();
		int cnt=0,ans=2e18;
		int lu=que[s].size();
		int lv=que[t].size();
		for(int i=0;i<lu;i++)
			for(int j=0;j<lv;j++)
			{
				cnt=w[s]+w[t]+dis[que[s][i].x][que[t][j].x];
				ans=min(ans,cnt+que[s][i].w+que[t][j].w);
			}
		write(ans);
		putchar('\n');
	}
	return 0;
}

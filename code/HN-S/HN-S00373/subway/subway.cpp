#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505;
const int M=500005;
const int INF=4e18;

int read()
{
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}

void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10) putchar(x+'0');
	else
	{
		write(x/10);
		int y=x%10;
		putchar(y+'0');
	}
}

int n,m,d,q;
vector<int> to[M],tim[M];
int w[M];
int k[N];

int f[N][N];

void init()
{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    f[i][j]=INF;
	
	for(int kkk=1;kkk<=m;kkk++)
	{
		for(int i=0;i<(int)to[kkk].size();i++)
		{
			for(int j=0;j<(int)to[kkk].size();j++)
			{
				int u=to[kkk][i];
				int v=to[kkk][j];
				if(u==v) f[u][v]=f[v][u]=0;
				f[u][v]=min(f[u][v],tim[kkk][i]+tim[kkk][j]);
				f[v][u]=min(f[v][u],tim[kkk][i]+tim[kkk][j]);
			}
		}
	}
	
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}

int solve(int x,int y)
{
	int ans=INF;
	for(int i=0;i<(int)to[x].size();i++)
	{
		for(int j=0;j<(int)to[y].size();j++)
		{
			int u=to[x][i];
			int v=to[y][j];
			int base=tim[x][i]+tim[y][j];
			ans=min(ans,base+f[u][v]);
		}
	}
	return ans+w[x]+w[y];
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_id=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			int x=read(),t=read();
			to[x].push_back(i);
			tim[x].push_back(t);
		}
	}
	
	init();
	
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		write(solve(x,y));
		puts("");
	}
	return 0;
}
//15.08 注意到题目等价于从 x 所在的某一线路到 y 所在的某一线路的最短路，其他的量都是定值 
//      发现 n<=500，直接跑一个 floyd，查询的时候枚举
//      这么做复杂度肯定是对的，因为 d<=20，复杂度是 d*d*q 的
//      建边：枚举所有站点，d^2 更新，可能会 S，但问题不大
//      总时间是 O(m+n+md^2+n^2+n^3+qd^2)，大约 4e8，相信评测机？ 
//15.45 finish

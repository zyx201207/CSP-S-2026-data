#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define gc() getchar()
#define pc(x) putchar(x)

int read()
{
	int x=0,f=1;
	char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}

void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');return ;}
	write(x/10);pc(x%10+'0');
	return ;
}

void print(int x)
{
	write(x);pc('\n');
	return ;
}

int dp[510][510];
int a[510][510];
int w[500010];
int TTT,n,m,d,Q;
struct node {int x,t;};
vector<node> v[500010];

void solve()
{
	int s=read(),t=read();
	int ans=1e18+7;
	for(auto S:v[s])
	{
		for(auto T:v[t])
		{
			ans=min(ans,S.t+T.t+a[S.x][T.x]);
		}
	}
	print(ans+w[s]+w[t]);
	return ;
}

void init()
{
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			a[i][j]=1e18+7;
		}
		a[i][i]=0;
	}
	for(int T=1;T<=n;T++)
	{
		int siz=v[T].size();
		for(int i=0;i<siz;i++)
		{
			for(int j=i+1;j<siz;j++)
			{
				a[v[T][i].x][v[T][j].x]=a[v[T][j].x][v[T][i].x]=min(a[v[T][j].x][v[T][i].x],v[T][i].t+v[T][j].t);
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=i+1;j<=m;j++)
			{
				a[j][i]=a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	return ;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TTT=read();m=read();n=read();d=read();Q=read();
	for(int i=1;i<=n;i++) {w[i]=read();}
	for(int i=1;i<=m;i++)
	{
		int ttk=read();
		for(int j=1;j<=ttk;j++)
		{
			int u=read(),t=read();
			v[u].push_back({i,t});
		}
	}
	init();
	while(Q--) {solve();}
	return 0;
}

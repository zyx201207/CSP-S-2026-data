#include<bits/stdc++.h>
using namespace std;
#define pc putchar_unlocked
#define gc getchar_unlocked
#define int long long
int w[505];
int f[505][505];
int g[505][505];
void read(int& x)
{
	x=0;
	bool flg=0;
	char ch=gc();
	while(ch<'0' ||  ch>'9') 
	{
		if(ch=='-') flg=1;
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=gc();
	}
	if(flg) x=-x;
}
void write(int x)
{
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j!=i) f[i][j]=g[i][j]=LLONG_MAX/10;
			else f[i][j]=g[i][j]=0;
		}
		read(w[i]);
	}
	for(int i=1,u,v,x;i<=n;i++)
	{
		read(c);read(u);read(x);read(v);read(c);
		g[u][v]=min(g[u][v],x);
		f[u][v]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min({f[i][j],f[i][k]+g[k][j],g[i][k]+f[k][j]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		read(x);read(y);
		write(f[x][y]+w[x]+w[y]);
		pc('\n');
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define int long long
inline void read(int &x)
{
	char c;
	c=getchar();
	int u=1;
	while(!isdigit(c))
	{
		if(c=='-')
		{
			u=-1;
		}
		c=getchar();
	}
	x=0;
	while(isdigit(c))
	{
		x=x*10;
		x+=c-'0';
		c=getchar();
	}
	x=x*u;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10)
	{
		write(x/10);
	}
	char c=x%10+'0';
	putchar(c);
}
const int N=5e5+5;
int w[N],di[600][600];
vector<PII>each[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
	{
		read(w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				di[i][j]=0;
				continue;
			}
			di[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		read(k);
		for(int j=1;j<=k;j++)
		{
			int da,t;
			read(da),read(t);
			for(auto e:each[da])
			{
				int a=i,b=e.first;
				if(a>b)
				{
					swap(a,b);
				}
				di[a][b]=min(di[a][b],e.second+t);
			}
			each[da].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=k;j<=n;j++)
			{
				di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
			}
		}
	}
	for(int j=1;j<=q;j++)
	{
		int l,r;
		read(l),read(r);
		int now=1e18;
		for(auto e1:each[l])
		{
			for(auto e2:each[r])
			{
				int a=e1.first,b=e2.first;
				if(a>b)
				{
					swap(a,b);
				}
				now=min(now,di[a][b]+e1.second+e2.second);
			}
		}
		write(w[l]+w[r]+now);
		putchar('\n');
	}
	return 0;
}
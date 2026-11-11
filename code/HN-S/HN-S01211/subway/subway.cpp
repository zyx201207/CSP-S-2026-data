#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
vector <array <int,2> > p[500010];//{line,time}
int ve[510][510];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		x=read();
		for (int j=1;j<=x;j++)
		{
			int a,t;
			a=read();
			t=read();
			p[a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j)
			{
				continue;
			}
			ve[i][j]=0x3f3f3f3f;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (auto t:p[i])
		{
			for (auto g:p[i])
			{
				int f=t[1]+g[1];
				if (ve[t[0]][g[0]]>f)
				{
					ve[t[0]][g[0]]=f;
					ve[g[0]][t[0]]=f;
				}
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				int t=ve[k][i]+ve[k][j];
				if (ve[i][j]>t)
				{
					ve[i][j]=t;
					ve[j][i]=t;
				}
			}
		}
	}
	for (int k=1;k<=q;k++)
	{
		int x,y,ans=0x3f3f3f3f;
		x=read();
		y=read();
		for (auto i:p[x])
		{
			for (auto j:p[y])
			{
				int t=w[x]+w[y]+i[1]+j[1]+ve[i[0]][j[0]];
				if (ans>t)
				{
					ans=t;
				}
			}
		}
		cout<<ans<<'\n';
	}
}


/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
1
*/

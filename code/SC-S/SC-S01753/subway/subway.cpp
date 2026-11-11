#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int a[500005];
int s[500005][25];
int r[500005][25];
long long x[505][505];

int read()
{
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}

long long mn(long long x,long long y)
{
	return x>y?y:x;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			x[i][j]=9e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		k=read();
		for(int j=1;j<=k;j++)
		{
			int u,v;
			u=read(),v=read();
			s[u][++s[u][0]]=i;
			r[u][++r[u][0]]=v;
			for(int k=1;k<s[u][0];k++)
			{
				x[s[u][k]][i]=x[i][s[u][k]]=mn(x[i][s[u][k]],v+r[u][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[j][i]==9e18) continue;
			for(int k=1;k<=n;k++)
			{
				if(j==k||x[i][k]==9e18) continue;
				x[j][k]=mn(x[j][k],x[j][i]+x[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		u=read(),v=read();
		long long ans=9e18;
		for(int j=1;j<=s[u][0];j++)
		{
			for(int k=1;k<=s[v][0];k++)
			{
				ans=mn(ans,x[s[u][j]][s[v][k]]+r[u][j]+r[v][k]+a[u]+a[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
fc C:\Users\user\Desktop\subway\subway7.ans C:\Users\user\Desktop\陈仟阅\subway.out
*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10,mod=998244353;
const ll inf=1e18;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) k=k*10+c-'0',c=getchar();
	return k*f;
}
int c,n,m,d,q,w[maxn],K[maxn];
ll f[510][510],e[510][510];
pii p[maxn][21];
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=e[i][j];
		f[i][i]=0;
	}
	for(int r=1;r<=n;r++)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i][r]==inf) continue;
			for(int j=1;j<=n;j++)
			{
				if(f[j][r]==inf or i==j) continue;
				f[i][j]=min(f[i][j],f[i][r]+f[r][j]);
			}
		}
	}
}
signed main()
{
 	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int sta=read(),t=read();
			p[sta][++K[sta]]={i,t};
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) e[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=K[i];j++)
		{
			for(int t=j+1;t<=K[i];t++) 
			{
				pii x=p[i][j],y=p[i][t];
				e[x.first][y.first]=min(e[x.first][y.first],(ll)x.second+y.second);
				e[y.first][x.first]=e[x.first][y.first];
			}
		}
	}
	floyd();
	while(q--)
	{
		int x=read(),y=read();
		ll ans=inf;
		for(int i=1;i<=K[x];i++)
		{
			for(int j=1;j<=K[y];j++)
			{
				pii a=p[x][i],b=p[y][j];
				ans=min(ans,(ll)w[x]+(ll)w[y]+(ll)a.second+(ll)b.second+f[a.first][b.first]); 
			}
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}


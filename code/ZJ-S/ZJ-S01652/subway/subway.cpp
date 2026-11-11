#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,mx,q,a[N],g[N][N],f[N][N];
ll val[N],pos[N];
inline ll read()
{
	ll flag=1,tmp=0;
	char ch=getchar();
	while(ch<48||ch>57)
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57)
	{
		tmp=tmp*10+ch-'0';
		ch=getchar();
	}
	return flag*tmp;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	c=read(),m=read(),n=read(),mx=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		ll k=read();
		for(int j=1;j<=k;j++)
		{
			pos[j]=read();
			val[j]=read();
			//cout<<i<<endl;
		}
		for(int x=1;x<=k;x++)
			for(int y=1;y<=k;y++)
			{
				ll u=pos[x],v=pos[y];
				//cout<<val[x]<<" "<<x<<" "<<val[y]<<" "<<y<<endl;
				g[u][v]=g[v][u]=min(g[u][v],val[x]+val[y]);
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)f[i][j]=g[i][j];
	//for(int i=1;i<=n;i++)
	//{
	//	for(int j=1;j<=n;j++)cout<<f[i][j]<<" ";
	//	cout<<endl;
	//}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
	while(q--)
	{
		ll s=read(),t=read();
		printf("%lld\n",a[s]+f[s][t]+a[t]);
	}
	return 0;
}
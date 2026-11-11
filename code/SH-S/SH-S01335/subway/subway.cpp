#include <cstdio>
const int N=510;
const int D=22;
const int M=500100;
const long long INF=1e18;
struct node
{
	int id;
	long long tim;
};
node tong[M][D];
int tot[M];
long long w[M];
long long G[N][N];
int len[N];
inline long long min(long long a,long long b)
{
	return (a < b) ? a : b;
}
int read()
{
	int num=0,f=1;
	char c=getchar();
	while(!(c>='0' && c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		w[i]=(long long)read();
//		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		len[i]=read();
		for(int j=1;j<=len[i];j++)
		{
			int a=read();
			long long t=(long long)read();
//			scanf("%d%lld",&a,&t);
			tong[a][++tot[a]]=(node){i,t};
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			G[i][j]=INF;
		}
		G[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=tot[i];j++)
		{
			for(int k=1;k<=tot[i];k++)
			{
				if(j==k) continue;
				G[tong[i][j].id][tong[i][k].id]=min(G[tong[i][j].id][tong[i][k].id],tong[i][j].tim+tong[i][k].tim);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==k || i==k) continue;
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	while(q--)
	{
		int u=read(),v=read();
//		scanf("%d%d",&u,&v);
		long long ans=INF;
		for(int i=1;i<=tot[u];i++)
		{
			for(int j=1;j<=tot[v];j++)
			{
				ans=min(ans,G[tong[u][i].id][tong[v][j].id]+w[u]+w[v]+tong[u][i].tim+tong[v][j].tim);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

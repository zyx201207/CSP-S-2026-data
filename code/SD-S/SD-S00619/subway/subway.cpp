#include<bits/stdc++.h>
#define INF 0x7f7f7f7f7f7f7f7f
using namespace std;
const int N=500+5,M=5e5+5;
int n,m,tot,W[M],head[M],Next[M*20],ver[M*20],edge[M*20];
long long E[N][N],dist[N][N];
inline int Read()
{
	int f=1,x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void Add(int a,int b,int c)
{
	ver[++tot]=b;
	edge[tot]=c;
	Next[tot]=head[a];
	head[a]=tot;
}
void Floyd()
{
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (dist[i][k]==INF||E[k][j]==INF) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+E[k][j]);
				dist[j][i]=dist[i][j];
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x7f,sizeof(dist));
	memset(head,-1,sizeof(head));
	memset(E,0x7f,sizeof(E));
	tot=0;
	int i,j,k,a,b,d,C,Q;
	C=Read(); n=Read(); m=Read(); d=Read(); Q=Read();
	for (i=1;i<=n;i++) dist[i][i]=0;
	for (i=1;i<=m;i++) W[i]=Read();
	for (i=1;i<=n;i++)
	{
		k=Read();
		for (j=1;j<=k;j++)
		{
			a=Read();b=Read();
			Add(a,i,b);
		}
	}
	for (k=1;k<=m;k++)
	{
		for (i=head[k];i!=-1;i=Next[i])
		{
			for (j=Next[i];j!=-1;j=Next[j])
			{
				a=ver[i];b=ver[j];
				E[a][b]=min(E[a][b],(long long)edge[i]+edge[j]);
				E[b][a]=E[a][b];
			}
		}
	}
	Floyd();
	while (Q--)
	{
		a=Read();b=Read();
		long long minn=INF;
		for (i=head[a];i!=-1;i=Next[i])
		{
			for (j=head[b];j!=-1;j=Next[j])
			{
				minn=min(minn,edge[i]+edge[j]+dist[ver[i]][ver[j]]);
			}
		}
		printf("%lld\n",minn+W[a]+W[b]);
	}
	return 0;
}


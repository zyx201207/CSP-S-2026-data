#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	bool bz=false;
	char ch=getchar();
	long long ans=0;
	while(ch!=EOF&&ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-')
	{
		bz=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=(ans<<3)+(ans<<1)+(ch^48);
		ch=getchar();
	}
	if(bz)
		return -ans;
	return ans;
}
void wrt(long long x)
{
	int numn[40],cnt=0,i;
	long long y=x;
	if(y<0)
	{
		putchar('-');
		y=-y;
	}
	do
	{
		numn[++cnt]=y%10;
		y/=10;
	}while(y);
	for(i=cnt;i>=1;--i)
		putchar(numn[i]^48);
	return;
}
const int maxm=5e5,maxn=500;
const long long inf=LLONG_MAX>>1;
struct edg
{
	int nxt,t;
	long long w;
}e[maxm+10];
int fst[maxm+10];
int c,n,m,d,q,p;
int cnt,a,u,v,x,y;
long long dis[maxn+10][maxn+10],w[maxm+10];
long long ans,t;
void ad(int x,int y,long long z)
{
	e[cnt].t=y;
	e[cnt].w=z;
	e[cnt].nxt=fst[x];
	fst[x]=cnt++;
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k;
	c=rd();
	n=rd();
	m=rd();
	d=rd();
	q=rd();
	for(i=1;i<=m;++i)
		w[i]=rd();
	memset(fst,-1,sizeof(fst));
	for(i=1;i<=n;++i)
	{
		p=rd();
		for(j=1;j<=p;++j)
		{
			a=rd();
			t=rd();
			ad(a,i,t);
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(i==j)
				dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(i=1;i<=m;++i)
	{
		for(j=fst[i];~j;j=e[j].nxt)
		{
			u=e[j].t;
			for(k=fst[i];~k;k=e[k].nxt)
			{
				v=e[k].t;
				dis[u][v]=min(dis[u][v],e[j].w+e[k].w);
				dis[v][u]=min(dis[v][u],e[j].w+e[k].w);
			}
		}
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--)
	{
		x=rd();
		y=rd();
		ans=inf;
		for(i=fst[x];~i;i=e[i].nxt)
		{
			u=e[i].t;
			for(j=fst[y];~j;j=e[j].nxt)
			{
				v=e[j].t;
				ans=min(ans,e[i].w+e[j].w+dis[u][v]);
			}
		}
		wrt(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}

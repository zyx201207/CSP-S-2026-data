#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pll;
const long long maxn=5e5+5,inf=5e17,maxk=400;
long long c,n,m,i,j,d,kc,s,t,q;
long long w[maxn],k[maxn],x[maxn],y[maxn],dis[405][405];
struct node
{
	long long xi,yi;
};
vector<node>ve[maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(i=1;i<=maxk;i++)
	{
		for(j=1;j<=maxk;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(j=1;j<=k[i];j++) scanf("%lld %lld",&x[j],&y[j]);
		for(j=1;j<k[i];j++)
		{
			for(c=j+1;c<=k[i];c++)
			{
				dis[x[j]][x[c]]=min(dis[x[j]][x[c]],y[j]+y[c]);
				dis[x[c]][x[j]]=min(dis[x[c]][x[j]],y[j]+y[c]);
			}
		}
	}
	for(kc=1;kc<=maxk;kc++)
	{
		for(i=1;i<=maxk;i++)
		{
			for(j=1;j<=maxk;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][kc]+dis[kc][j]);
			}
		}
	}
	while(q--)
	{
		scanf("%lld %lld",&s,&t);
		printf("%lld\n",dis[s][t]+w[s]+w[t]);
	}
	return 0;
}//Oct31==Dec25?
//luogu uid:562443
//My fifth CSP
//Not for anyone,just for me.
//;;
//freopen y1 genshin
//数据删除 查无此人
//Oct31==Dec25?
//16岁!
//Asz->XJ OIer->MOer
//for my love.
//
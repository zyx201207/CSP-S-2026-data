#include<stdio.h>
#include<queue>
using namespace std;
int dis[5000][5000];
int cnt[5000][5000];
long long x[5000];
int rmax[5000];
int lmin[5000];
int from[5000];
queue<long long> q;
int count(int u,int y,int d)
{
//	printf("COUNT %d %d dep:%d\n",u,y,d);
	if(d<0||u>y)
	{
		return 0;
	}
	if(u==y)
	{
		return 1;
	}
	int i;
	int cnt=0;
	for(i=u[rmax];i>u;--i)
	{
		cnt+=count(i,y,d-1);
		if(cnt>2)
		{
			return 3;
		}
	}
//	printf("RES:%d\n",cnt);
	return cnt;
}
void f()
{
	int n,i,j;
	long long d;
	int ans=0;
	scanf("%d%lld",&n,&d);
	for(i=0;i<n;++i)
	{
		i[lmin]=-1;
	}
	for(i=0;i<n;++i)
	{
		scanf("%lld",x+i);
		q.push(i);
		while(q.front()[x]<x[i]-d)
		{
			q.front()[rmax]=i-1;
			q.pop();
		}
		i[lmin]=q.front();
	}
	while(!q.empty())
	{
		q.front()[rmax]=n-1;
		q.pop();
	}
	for(i=0;i<n;++i)
	{
		dis[i][i]=0;
		i[from]=i;
		for(j=i+1;j<n;++j)
		{
			dis[i][j]=dis[i][(j-1)[from]];
			j[from]=(j-1)[from];
			if((j-1)[from][rmax][x]<j[x])
			{
				dis[i][j]++;
				j[from]=j;
			}
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			ans+=count(i,j,dis[i][j]+1)==2;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,i;
	scanf("%*d%d",&n);
	for(i=0;i<n;++i)
	{
		f();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

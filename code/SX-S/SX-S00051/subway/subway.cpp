#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5,maxm=5e5+5;
int c,n,m,dd,q,ds[maxm];
long long w[maxm],dis[maxn][maxn];
pair<int,int> d[maxm][20];
long long read()
{
	char cc=getchar();
	long long ans=0;
	while(cc>='0'&&c<='9')
		ans=(ans<<3)+(ans<<1)+cc-'0',cc=getchar();
	return ans;
}
void solve()
{
	c=read();
	n=read();
	m=read();
	dd=read();
	q=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=0x3F3F3F3F3F3F3F3F;
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=0,k,a,b;i<n;i++)
	{
		k=read();
		for(int j=0;j<k;j++)
		{
			a=read();
			b=read();
			for(int p=0;p<ds[a];p++)
			{
				int v=(d[a]+p)->first;
				dis[v][i]=dis[i][v]=min(dis[v][i],0LL+(d[a]+p)->second+b);
			}
			d[a][ds[a]++]={i,b};
		}
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	//for(int i=0;i<n;i++,printf("\n"))
	//	for(int j=0;j<n;j++)
	//		printf("%lld ",dis[i][j]);
	//for(int i=0;i<=m;i++)
	//	printf("%d ",w[i]);
	//printf("\n");
	for(int i=0,s,t;i<q;i++)
	{
		s=read();
		t=read();
		long long ans=0x3F3F3F3F3F3F3F3F;
		for(int j=0;j<ds[s];j++)
			for(int k=0;k<ds[t];k++)
			{
				int ss=d[s][j].first,tt=d[t][k].first;
				ans=min(ans,w[s]+w[t]+dis[ss][tt]+d[s][j].second+d[t][k].second);
			}
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int TT = 1;
	//scanf("%d",&TT);
	while (TT--)
		solve();
	return 0;
}

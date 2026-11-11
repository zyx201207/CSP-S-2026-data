#include<bits/stdc++.h>
using namespace std;
const int N=515,M=5e5+15,D=30;
const long long inf=2e18;
int Type,n,m,MxL,Q,nn[N],d[M],st,en;
long long T[M],a[N][N],mn,x;
long long in()
{
	char ch=getchar();
	long long sum=0;
	while(!isdigit(ch))
	  ch=getchar();
	while(isdigit(ch))
	  sum=sum*10+ch-48,ch=getchar();
	return sum;
}
struct pig
{
	int line;
	long long t;
}c[M][D];
void FR()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int main()
{
	FR();
	Type=in(),n=in(),m=in(),MxL=in(),Q=in();
	for(int i=1;i<=m;++i)
	  T[i]=in();
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    a[i][j]=inf;
	for(int i=1;i<=n;++i)
	{
		nn[i]=in(),a[i][i]=0;
		for(int j=1;j<=nn[i];++j)
		  x=in(),c[x][++d[x]]={i,in()};
	}
	for(int i=1;i<=m;++i)
	  for(int j=1;j<=d[i];++j)
		for(int k=1;k<=d[i];++k)
		  a[c[i][j].line][c[i][k].line]=min(a[c[i][j].line][c[i][k].line],c[i][j].t+c[i][k].t);
	for(int k=1;k<=n;++k)
	  for(int i=1;i<=n;++i)
	    for(int j=1;j<=n;++j)
	      a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	while(Q--)
	{
		st=in(),en=in();
		mn=inf;
		for(int i=1;i<=d[st];++i)
		  for(int j=1;j<=d[en];++j)
		    mn=min(mn,T[st]+T[en]+c[st][i].t+c[en][j].t+a[c[st][i].line][c[en][j].line]);
		printf("%lld\n",mn);
	}
	return 0;
}
//100 latest

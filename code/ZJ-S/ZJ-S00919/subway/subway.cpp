#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,n,m,l,o,i,j,k,p,x,y,a[500001],num[501],f[501][501],g[500001][21],h[500001][21],min_;
struct subway
{
	int x,tim;
	friend bool operator<(subway x,subway y)
	{
		if(x.x<y.x)
		  return true;
		return false;
	}
};
vector<subway>b[501];
int getint()
{
	int sum=0;
	char a=getchar();
	while(a<48||a>57)
	  a=getchar();
	while(a>=48&&a<=57)
	{
		sum=sum*10+a-48;
		a=getchar();
	}
	return sum;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,63,sizeof(f));
	id=getint();
	n=getint();
	m=getint();
	l=getint();
	o=getint();
	for(i=1;i<=m;i++)
	   a[i]=getint();
	for(i=1;i<=n;i++)
	{
		num[i]=getint();
		b[i].resize(num[i]);
		for(j=1;j<=num[i];j++)
		{
			b[i][j-1].x=getint();
			b[i][j-1].tim=getint();
		}
		sort(b[i].begin(),b[i].end());
	}
	for(i=1;i<=n;i++)
	   f[i][i]=0;
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      if(i!=j)
	        for(k=p=0;k<num[i]&&p<num[j];k++)
	        {
	        	for(;p<num[j]&&b[j][p].x<b[i][k].x;p++);
	        	if(p<num[j]&&b[j][p].x==b[i][k].x)
	        	  f[i][j]=min(f[i][j],b[j][p].tim+b[i][k].tim);
			}
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      for(k=1;k<=n;k++)
	         f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	for(i=1;i<=n;i++)
	   for(j=0;j<num[i];j++)
	   {
	   	g[b[i][j].x][0]++;
	   	g[b[i][j].x][g[b[i][j].x][0]]=i;
	   	h[b[i][j].x][g[b[i][j].x][0]]=b[i][j].tim;
	   }
	for(i=1;i<=o;i++)
	{
		min_=1000000000000000000ll;
		scanf("%lld%lld",&x,&y);
		for(j=1;j<=g[x][0];j++)
		   for(k=1;k<=g[y][0];k++)
		      min_=min(min_,a[x]+a[y]+h[x][j]+h[y][k]+f[g[x][j]][g[y][k]]);
		printf("%lld\n",min_);
	}
	return 0;
}

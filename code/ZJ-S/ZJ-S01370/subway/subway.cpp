#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+5,maxn=5e2+5;
const long long inf=1e18;
struct node{
	int v;
	long long w;
};
int n,m,c,d,q,k[maxn],w[maxm];
long long f[maxn][maxn],ans;
vector<node>a[maxm];
inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	  {
	  	if(ch=='-')
	  	  f=-1;
	  	ch=getchar();
	  }
	while(ch>='0'&&ch<='9')
	  x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)
	  w[i]=read();
	for(int i=1;i<=n;i++)
	  {
	  	k[i]=read();
	  	for(int j=1;j<=k[i];j++)
	  	  {
	  	  	int u,w;
	  	  	u=read();
	  	  	w=read();
	  	  	node c,b;
	  	  	c.v=u;
	  	  	c.w=w;
	  	  	b.v=m+i;
	  	  	b.w=w;
	  	  	a[m+i].push_back(c);
	  	  	a[u].push_back(b);
		  }
	  }
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	  f[i][i]=0;
	for(int i=1;i<=m;i++)
	  {
	  	for(int j=0;j<a[i].size();j++)
	  	  for(int k=0;k<a[i].size();k++)
	  	    f[a[i][j].v-m][a[i][k].v-m]=min(f[a[i][j].v-m][a[i][k].v-m],a[i][j].w+a[i][k].w);
	  }
//	for(int l=1;l<=n;l++)
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      f[i][k]=min(f[i][k],f[j][k]+f[i][j]);
	while(q--)
	  {
	  	int x,y;
	  	x=read();
	  	y=read();
	  	ans=inf;
	  	for(int i=0;i<a[x].size();i++)
	  	  {
	  	  	node p=a[x][i];
	  	  	for(int j=0;j<a[y].size();j++)
	  	  	  {
	  	  	  	node q=a[y][j];
	  	  	  	ans=min(ans,f[p.v-m][q.v-m]+p.w+q.w);
			  }
		  }
		printf("%lld\n",ans+w[x]+w[y]);
	  }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,inf=0x3f3f3f3f;
int t,n,mi[maxn],c,v[maxn];
long long x[maxn],d,ans,f[maxn];
inline long long read()
{
	long long f=1,x=0;
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	  {
	  	n=read();
	  	d=read();
	  	for(int i=1;i<=n;i++)
	  	  x[i]=read();
	  	ans=0;
	  	if(c==11||c==12)
	  	  {
	  	  	if(((x[2]-x[1])<<1)>d)
	  	  	  printf("0\n");
			else
			  {
			  	long long y=d/(x[2]-x[1]);
			  	ans=ans+(n-min(y*2-1,1ll*n));
			  	printf("%lld\n",ans);
			  }
	  	  	continue;
		  }
		if(c==13||c==14)
		  {
		  	printf("0\n");
		  	continue;
		  }
	  	for(int i=1;i<=n;i++)
	  	  {
			mi[i]=0;
	  	  	v[0]=1;
	  	  	f[0]=1;
	  	  	int k=i;
	  	  	for(int j=i+1;j<=n;j++)
	  	  	  {
	  	  	  	while(x[j]-x[k]>d)
	  	  	  	  v[mi[k]]-=f[k],k++;
	  	  	  	if(j==k)
	  	  	  	  break;
	  	  	  	mi[j]=mi[k]+1;
				f[j]=v[mi[j]-1];
	  	  	  	v[mi[j]]=v[mi[j]]+v[mi[j]-1];
	  	  	  	if(v[mi[j]-1]==2)
	  	  	  	  ans++;
		   	  }
		   	for(int j=k;j<=n;j++)
		   	  v[mi[j]]-=f[j];
		  }
		printf("%d\n",ans);
	  }
	return 0;
}

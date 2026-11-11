#include<bits/stdc++.h>
using namespace std;
int n,p,q,r,b[2000005],c[2000005],d[2000005],e[2000005],f[2000005],g[2000005],h[2000005],k[2000005];
long long m,s,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&p,&p);
	for(int i=1;i<=p;i++)
	{
		scanf("%d%lld",&n,&m);
		q=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			while(a[j]-a[q]>m)q++;
			b[j]=q;
			c[q]=j;
		}
		while(q<=n)c[q++]=n;
		for(int j=1;j<n-2;j++)
		{
			if(c[j]==j+2&&c[j+1]==j+3)
			{
				d[++r]=j+3;
				e[r]=j;
				f[j+3]=1;
				g[j]=1;
			}
			f[j+3]+=f[j+2];
			g[j]+=g[j-1];
		}
		if(n>3)
		{
			g[n]=g[n-3];
			g[n-1]=g[n];
			g[n-2]=g[n];
		}
		for(int j=1;j<=n;j++)
			h[j]=h[b[j]]+j-b[j]-f[j]+f[b[j]];
		for(int j=n;j;j--)
			k[j]=k[c[j]]+c[j]-j-g[c[j]-1]+g[j-1];
		for(int j=1;j<=r;j++)
			s+=1ll*(h[e[j]]+1)*(k[d[j]]+1);
		printf("%lld\n",s);
		s=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e6+10,mod=998244353,inf=1e18;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) k=k*10+c-'0',c=getchar();
	return k*f;
}
int n,d,x[maxn],r[maxn],ans,mxdep,f[maxn],g[maxn];
void init()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read(),ans=0;
}
void solve()
{
	init();
	r[n]=n;
	for(int i=n-1,j=n;i>=1;i--)
	{
		while(x[j]>x[i]+d) j--;
		r[i]=j;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1,g[i]=0;
		for(int j=i+1;j<=n;j++) g[j]=inf,f[j]=-1;
		for(int j=i;j<=n;j++)
		{
			if(f[j]==-1) continue;
			else if(f[j]==2) ans++;
			for(int k=j+1;k<=r[j];k++)
			{
				if(g[j]+1<g[k]) f[k]=f[j],g[k]=g[j]+1;
				else if(g[j]+1==g[k]) f[k]+=f[j];
				if(f[k]>2) f[k]=-1;
			}
			
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
 	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--) solve();	
	return 0;
}
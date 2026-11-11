#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int n,d,x[N],nxt[N],pre[N],cn[N],cp[N],ans;
int dp1[N],dp2[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void solve()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	int pt=n;
	for(int i=n;i>=1;i--)
	{
		while(pt>1&&x[pt]-x[i]>d) pt--;
		nxt[i]=pt;
		if(nxt[i]!=i) cn[nxt[i]]++;
	}
	
	pt=1;
	for(int i=1;i<=n;i++)
	{
		while(pt<n&&x[i]-x[pt]>d) pt++;
		pre[i]=pt;
		if(pre[i]!=i) cp[pre[i]]++;
	}
	
	for(int u=1;u<=n;u++)
	{
		dp1[u]=cn[u];
		if(pre[u]<u&&nxt[pre[u]]==u) dp1[u]+=dp1[pre[u]];
	}
	for(int u=n;u>=1;u--)
	{
		dp2[u]=cp[u];
		if(nxt[u]>u&&pre[nxt[u]]==u) dp2[u]+=dp2[nxt[u]];
	}
	
	ans=0;
	for(int x=1;x<n;x++)
	{
		if(nxt[x]==x) continue;
		int cntl=0,cntr=0;
		cntl=cn[x+1]-(nxt[x]==x+1);
		cntr=cp[x]-(pre[x+1]==x);
		
		if(nxt[pre[x]]==x+1) cntl+=dp1[pre[x]];
		if(pre[nxt[x+1]]==x) cntr+=dp2[nxt[x+1]];
		ans+=cntl*cntr;
	}
	printf("%lld\n",ans);
}
void clear()
{
	for(int i=0;i<=n;i++) cn[i]=cp[i]=0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--) solve(),clear();
	return 0;
}

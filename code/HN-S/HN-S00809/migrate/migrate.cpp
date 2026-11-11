#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int read()
{
	int x(0),f(1);
	char ch(getchar());
	while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}

const int N=2e6+5;
int n,d,a[N],to[N],numr[N],pre[N],numl[N],f[N],g[N];

inline void Work()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),numr[i]=numl[i]=to[i]=pre[i]=0;
	to[0]=0;
	for(int i=1;i<=n;i++)
	{
		to[i]=max(to[i-1],i);
		while(to[i]<n&&a[to[i]+1]-a[i]<=d)
			to[i]++;
		if(to[i]!=i)
			numr[to[i]]++;
	}
	pre[n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		pre[i]=min(pre[i+1],i);
		while(pre[i]>1&&a[i]-a[pre[i]-1]<=d)
			pre[i]--;
		if(pre[i]!=i)
			numl[pre[i]]++;
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=numr[i];
		if(to[pre[i]]==i&&to[pre[i]-1]<i)
			f[i]+=f[pre[i]];
	}
	g[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		g[i]=numl[i];
		if(pre[to[i]]==i)
			g[i]+=g[to[i]];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int L=numr[i],R=numl[i-1];
		if(pre[i]==i-1)
			R--;
		if(to[pre[i]]==i&&to[pre[i]-1]<i-1)
			L+=f[pre[i]];
		if(pre[to[i]]==i-1)
			R+=g[to[i]];
		ans+=L*R;
	}
	cout<<ans<<"\n";
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c(read()),T(read());
	while(T--)
		Work();
	return 0;
}
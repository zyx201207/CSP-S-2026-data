#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[2000010];
int nxt[2000010],pre[2000010];
int numnxt[2000010],numpre[2000010];
int sumnxt[2000010],sumpre[2000010];
int posl[2000010],posr[2000010];
int pposl[2000010],pposr[2000010];
int solve()
{
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++) numnxt[i]=numpre[i]=sumnxt[i]=sumpre[i]=0;
	for(int i=1;i<=n;i++) posl[i]=posr[i]=pposr[i]=0,pposl[i]=n+1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n && a[j+1]-a[i]<=m) j++;
		nxt[i]=j;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>1 && a[i]-a[j-1]<=m) j--;
		pre[i]=j;
	}
	//~ printf("nxt : ");for(int i=1;i<=n;i++) printf("%lld ",nxt[i]);printf("\n");
	//~ printf("pre : ");for(int i=1;i<=n;i++) printf("%lld ",pre[i]);printf("\n");
	for(int i=n,j=n;i>=1;i--)
	{
		j=nxt[i]+1;
		while(j-1>i && pre[j-1]==i) j--;
		if(pre[nxt[i]]==i) sumnxt[i]=sumnxt[nxt[i]]+(numnxt[i]=(nxt[i]-j+1));
	}
	for(int i=1,j;i<=n;i++)
	{
		j=pre[i]-1;
		while(j+1<i && nxt[j+1]==i) j++;
		if(nxt[pre[i]]==i) sumpre[i]=sumpre[pre[i]]+(numpre[i]=(j-pre[i]+1));
	}
	for(int i=1;i<=n;i++) posr[pre[i]]=pposr[pre[pre[i]]]=i;
	for(int i=n;i>=1;i--) posl[pre[i]]=pposl[pre[pre[i]]]=i;
	for(int i=2;i<=n;i++) if(!pposr[i]) pposr[i]=pposr[i-1];
	//~ printf("sumnxt : ");for(int i=1;i<=n;i++) printf("%lld ",sumnxt[i]);printf("\n");
	//~ printf("sumpre : ");for(int i=1;i<=n;i++) printf("%lld ",sumpre[i]);printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(nxt[nxt[i]]==nxt[i]) continue;
		int j=nxt[i],k=nxt[nxt[i]];
		int cntl=sumpre[i],cntr=0,tot=0;
		int L=j+1,R=k;
		L=max(L,posl[j-1]);R=min(R,posr[j-1]);
		R=min(R,pposr[i]);tot+=max(0ll,R-L+1);
		L=max(L,pposl[i]);cntr+=max(0ll,R-L+1);
		if(pre[k]==j-1 && pre[pre[k]]==i) cntr+=sumnxt[k];
		if(pre[k]==j-1 && pre[pre[k]]<=i) tot+=sumnxt[k];
		tot+=cntl*cntr;
		ans+=tot;
	}
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tid,t;
	cin>>tid>>t;
	while(t--)printf("%lld\n",solve());
}

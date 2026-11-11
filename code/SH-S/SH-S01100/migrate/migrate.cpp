#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],lst[N],nxt[N],s1[N],s2[N],s3[N],s4[N],s5[N],s6[N];
void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=0;i<=n+1;i++)
	{
		a[i]=lst[i]=nxt[i]=s1[i]=s2[i]=s3[i]=s4[i]=s5[i]=s6[i]=0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	int p=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[p]>d)p++;
		lst[i]=p;
	}
	p=n;
	for(int i=n;i;i--)
	{
		while(a[p]-a[i]>d)p--;
		nxt[i]=p;
	}
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]>i)s1[nxt[i]]++;
	}
	for(int i=n;i;i--)
	{
		if(lst[i]<i)s2[lst[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		s3[i]+=s1[i];
		if(nxt[i]>i&&lst[nxt[i]]==i)s3[nxt[i]]+=s3[i];
	}
	for(int i=n;i;i--)
	{
		s4[i]+=s2[i];
		if(lst[i]<i&&nxt[lst[i]]==i)s4[lst[i]]+=s4[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]>i+1)s5[nxt[i]]++;
	}
	for(int i=n;i;i--)
	{
		if(lst[i]<i-1)s6[lst[i]]++;
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		int x=s5[i],y=s6[i-1];
		if(lst[nxt[i]]==i-1)
		{
			y+=s4[nxt[i]];
		}
		if(nxt[lst[i-1]]==i)
		{
			x+=s3[lst[i-1]];
		}
		ans+=x*y;
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int cid,T;
	cin>>cid>>T;
	while(T--)solve();
}

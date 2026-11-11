#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
const int N=2e6+10;
int ccc,t,n;llo m,a[N];
int he[N],ne[N],e[N],dd,h[N],sz[N],f[N],mi[N],mii[N],p;
void add(int x,int y)
{
	ne[++dd]=he[x];
	he[x]=dd;e[dd]=y;f[y]=x;
}
void dfs(int u,int fa)
{
	p=min(p,u-1);
	h[u]=h[fa]+1;
	int hh=h[u];sz[hh]++;
	if(u<mi[hh])mii[hh]=mi[hh],mi[hh]=u;
	else mii[hh]=min(mii[hh],u);
	for(int i=he[u];i;i=ne[i])
	{
		int o=e[i];
		dfs(o,u);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>ccc>>t;
	while(t--)
	{
		cin>>n>>m;p=n;
		long long ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<=n+1;i++)he[i]=0,mi[i]=mii[i]=n+1,sz[i]=0,f[i]=0;dd=0;
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n;
			while(l<r)
			{
				int mid=(l+r+1>>1);
				if(a[mid]-a[i]>m)r=mid-1;
				else l=mid;
			}
			if(l>i)add(l,i);
		}
		while(p)
		{
			dfs(n,0);
			int a=0,b=0,c=0,x0=0,x1=0;
			for(int i=h[p+1],j=p+1;i;i--)
			{
				int aa=0,bb=0,cc=0;
				if(f[x0]==mi[i])
				{
					aa+=a;bb+=b;
					ans+=1ll*b*sz[i];
				}
				else if(f[x0]==mii[i])
				{
					bb+=a;
					ans+=1ll*(sz[i]-2);
				}
				//cout<<ans<<"*\n";
				if(f[x1]==mi[i])
				{
					bb+=c;ans+=1ll*sz[i]*c;
				}
				else if(f[x1]==mii[i])
				{
					if(f[x0]==mi[i])ans+=a+1;
					ans+=c;
				}
				//cout<<a<<" "<<b<<" "<<c<<" "<<x0<<" "<<x1<<" "<<ans<<endl;
				while(h[j]==i+1&&j<=n)
				{
					if(f[j]==mi[i])
					{
						aa++;
					}
					else if(f[j]==mii[i])
					{
						cc++;
						ans+=sz[i]-2;
					}
					j++;
				}
				x0=mi[i];x1=mii[i];
				a=aa,b=bb,c=cc;
				//cout<<a<<" "<<b<<" "<<c<<" "<<x0<<" "<<x1<<" "<<ans<<endl;
			}
			int ll=0;
			while(n>p)
			{
				n--;
				mi[++ll]=p+1;
				mii[ll]=p+1;
				sz[ll]=0;
			}
			n=p;
		}
		cout<<ans<<endl;
	}
	return 0;
}
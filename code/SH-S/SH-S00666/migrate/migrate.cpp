#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int t,a[N],l[N],r[N],f[N],g[N];
int solve(int n)
{
//	cout<<n<<endl;
	if(n==1) return 0;
	if(n==2) return 0;
	a[0]=0;
	a[n+1]=0;
	for(int i=0;i<=n+1;i++) f[i]=g[i]=0;
	for(int i=0;i<=n+1;i++) l[i]=r[i]=0;
	int pl=1,pr=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(pl<=i-1&&abs(a[pl]-a[i])>t) pl++;
		while(pr<=n-1&&abs(a[pr+1]-a[i])<=t) pr++;
		l[i]=pl;
		r[i]=pr;
//		cout<<l[i]<<" "<<r[i]<<endl;
	}
	f[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		if(i==1) f[i]=r[1];
		else f[i]=r[i]-r[i-1];
		if(r[i-1]!=r[i]) f[i]+=f[r[i]];
	}
	g[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(i==n) g[i]=n+1-l[n];
		else g[i]=l[i+1]-l[i];
		if(l[i+1]!=l[i]) g[i]+=g[l[i]];
	}
	for(int i=2;i<=n-2;i++)
	{
		int la=0,ra=0;
		if(l[i]!=l[i+1])
		{
			la=max(0ll,min(i-1,l[i+2]-1)-l[i+1]+1);
		}
		else
		{
			if(l[i+1]!=l[i+2]) la=l[i+2]-l[i+1]+g[l[i]];
		}
		if(r[i]!=r[i+1])
		{
			ra=max(0ll,r[i]-max(r[i-1]+1,i+1)+1);
		}
		else
		{
			if(r[i]!=r[i-1]) ra=r[i]-r[i-1]+f[r[i]];
		}
		int tmp=la*ra;
//		cout<<i<<" "<<la<<" "<<ra<<" "<<tmp<<endl; 
		ans+=tmp;
	}
	return ans;
}
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,tt;
	cin>>cc>>tt;
	while(tt--)
	{
		int n,c=0,ans=0;
		cin>>n>>t;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(c==0) a[++c]=x;
			else
			{
				if(abs(x-a[c])>t)
				{
					ans+=solve(c);
					c=1;
					a[c]=x;
				}
				else a[++c]=x;
			}
		}
		ans+=solve(c);
		cout<<ans<<'\n';
	}
	return 0;
}


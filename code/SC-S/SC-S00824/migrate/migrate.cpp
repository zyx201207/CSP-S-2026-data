#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int test,T;
int n,d,ans,f[N],a[N],lst[N],g[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>test>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i],lst[i]=f[i]=g[i]=0;
		a[n+1]=a[n]+d;
		for(int i=1;i<=n;++i)
		{
			int l=lower_bound(a+1,a+i+1,a[i]-d)-a,r=lower_bound(a+1,a+i+1,a[i+1]-d)-a;
			if(a[i+1]-d>a[i-1]&&a[i]-d<=a[i-1])
				lst[i]=lst[i-1]+1;
			g[i]=r-l+(r>l)*lst[l];
		}
		for(int i=1;i<=n;++i)
		{
			int l=lower_bound(a+1,a+i+1,a[i]-d)-a;
			if(i==l)f[i]=0;
			else if(l+1==i)ans+=(f[i]=f[l]-f[l-1]);
			else if(l+2==i)
			{
				int ll=lower_bound(a+1,a+i+1,a[l+1]-d)-a,lll=lower_bound(a+1,a+i+1,a[l]-d)-a;
				if(ll==l)f[i]=0;
				else	ans+=(f[i]=l-ll+g[ll]);
				ans+=f[ll-1]-f[lll-1],f[i]+=f[ll-1]-f[lll-1];
			}
			else
			{
				int rr=lower_bound(a+1,a+i+1,a[l+2]-d)-a,ll=lower_bound(a+1,a+i+1,a[l+1]-d)-a,lll=lower_bound(a+1,a+i+1,a[l]-d)-a;
				if(ll==rr)f[i]=0;
				else	ans+=(f[i]=rr-ll+g[ll]);
				ans+=f[ll-1]-f[lll-1],f[i]+=f[ll-1]-f[lll-1];
			}
			f[i]+=f[i-1];
//			cout<<f[i]<<"\n "[i<n];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
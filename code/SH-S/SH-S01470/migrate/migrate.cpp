#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000005;
int c,t,n,cnt,l[N],r[N],f[N],g[N];
ll d,a[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--)
	{
		cnt++;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		int j=1;
		for(int i=1;i<=n;++i)
		{
			while(a[i]-a[j]>d) j++;
			l[i]=j;
		}
		j=n;
		for(int i=n;i>=1;--i)
		{
			while(a[j]-a[i]>d) j--;
			r[i]=j;
		}
		for(int i=1;i<=n;++i) 
		{
			f[i]=g[i]=1;
		}
		for(int i=1;i<=n;++i)
			if(i==r[l[i]]) f[i]+=f[l[i]];
		j=0;ans=0;
		for(int i=1;i<=n;++i)
		{
			if(j<l[i]&&r[j]-l[i]==1&&r[j]<i) ans+=f[j];
			while(j<i&&r[j+1]-1<=l[i])
			{
				j++;
				if(j<l[i]&&r[j]-l[i]==1&&r[j]<i) 
					ans+=g[i];
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

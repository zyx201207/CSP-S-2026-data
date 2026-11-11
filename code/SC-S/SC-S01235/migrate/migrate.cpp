#include<bits/stdc++.h>
#define int long long
using namespace std;

int csd,T,n,m,l,r,k,s,ans,mid,a[2000001],f[2000001],z[2000001];

void dfs(int now,int step)
{
	if(step==f[now]) ++z[now];
	if(now==n) return;
	for(int i=now+1;i<=n;++i)
	{
		if(a[i]-a[now]>m) break;
		dfs(i,step+1);
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>csd>>T;
    while(T--)
    {
    	ans=0;
    	cin>>n>>m;
    	for(int i=1;i<=n;++i) cin>>a[i];
    	for(int i=1;i<=n;++i)
    	{
    		for(int j=i;j<=n;++j) f[j]=0;
    		for(int j=i;j<=n;++j) z[j]=0;
    		f[i]=1;
    		k=i;
    		s=0;
    		while(k<n)
    		{
    			l=k+1;
    			r=n;
    			while(l<=r)
    			{
    				mid=(l+r)/2;
    				if(a[mid]-a[k]>m) r=mid-1;
    				else l=mid+1;
				}
				if(r==k) break;
				++s;
    			for(int j=k+1;j<=r;++j) f[j]=s;
    			k=r;
			}
			dfs(i,0);
			for(int j=i+1;j<=n;++j) if(z[j]==2) ++ans;
		}
		cout<<ans<<endl;
	}
    return 0;
}













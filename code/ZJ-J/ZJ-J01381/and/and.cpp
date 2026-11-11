#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum,ans,a[200005],c[200005],g[200005][35];
int cnt,b[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		for(int j=0;j<=31;++j)
			if((a[i]>>j)&1ll){
				g[i][j]=1;	
			}
	}
	for(int i=1;i<=n;++i)
		b[++cnt]=i;
	for(int j=31;j>=0;--j)
	{
		if(cnt==m)
		{
			bool flag=true;
			for(int i=1;i<=cnt;++i)
				if(!g[b[i]][j])
					flag=false;
			if(flag){
				ans+=(1ll<<j);
			}
			continue;
		}
		sum=0;
		for(int i=1;i<=cnt;++i)
			if(g[b[i]][j])
			{
				c[++sum]=b[i];
			}
		if(sum>=m)
		{
			ans+=(1ll<<j);
			cnt=0;
			for(int i=1;i<=sum;++i)
				b[++cnt]=c[i];		
		}	
	}
	cout<<ans;
	return 0;
}

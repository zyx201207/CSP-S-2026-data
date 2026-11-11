#include <bits/stdc++.h>
using namespace std;
const int N=2e6;
int c,t,n,l,r,f[N],q[N];
long long d,x[N],ans,g[N];
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		l=1,r=0;
		memset(f,0,sizeof(f));memset(g,0,sizeof(g));
		f[i]=0,g[i]=1,q[++r]=i;
		for(int j=i+1;j<=n;j++)
		{
			
			while(l<=r&&x[q[l]]+d<x[j]) l++;
			f[j]=f[q[l]]+1;
			for(int k=l;k<=r&&f[q[k]]==f[q[l]];k++)
			{
				g[j]+=g[q[k]];
				if(g[j]>2) break;	
			}
			while(l<=r&&f[q[r]]>f[j]) r--;
			q[++r]=j;
			if(g[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

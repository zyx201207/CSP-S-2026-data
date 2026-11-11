#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const int maxn=2e6+5;
int n;
llt d,x[maxn],b[maxn],pre[maxn],suf[maxn],ans,f[maxn],g[maxn],h[maxn];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
//	n=7;
	if(n<=3)
	{
		cout<<0<<"\n";
		return;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(j>i&&x[j]-x[i]<=d) cout<<1;
//			else cout<<0;
//		}
//		cout<<"\n";
//	}
//	f[1]=g[1]=h[1]=1;
//	for(int i=2;i<=n;i++)
//	{
//		int t=lower_bound(x+1,x+n+1,x[i]-d)-x;
//		if(t-1>=0&&i>=t) g[i]=h[i-1]-h[t-1]+1;
//		if(i>=t) f[i]=f[t]+1;
//		h[i]=h[i-1]+f[i];
//	}
	b[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(x[i-1]+d>=x[i]&&(i-2<1||x[i-2]+d<x[i])&&(i+1>n||x[i+1]-x[i-1]>d)) b[i]=1;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<g[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<f[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(b[i]) pre[i]=b[i]+pre[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(b[i]) suf[i]=b[i]+suf[i+1];
	}
	for(int l=1,r=1;r<=n;r++)
	{
		int pp=upper_bound(x+1,x+n+1,x[l]+d)-x-1;
		int qq=lower_bound(x+1,x+n+1,x[r]-d)-x;
		while(l+4<=r&&pp-qq+1<=1)
		{
			l++;
			pp=upper_bound(x+1,x+n+1,x[l]+d)-x-1;
		}
//		cout<<l<<" "<<r<<" "<<pp<<" "<<qq<<"\n";
		if(pp-qq+1==2&&x[l]+d<x[r])
		{
			int tt=lower_bound(x+1,x+n+1,x[pp+1]-d)-x-1;
			ans+=(pre[l]-b[l]+1)*(suf[r+1]+1)*(tt-l+1);
//			cout<<l<<" "<<r<<" "<<(pre[l]-b[l]+1)<<" "<<(suf[r+1]+1)<<" "<<(tt-l+1)<<"\n";
		}
	}
	cout<<ans<<"\n";
	ans=0;
	for(int i=0;i<=n+1;i++)
	{
		b[i]=pre[i]=suf[i]=0;
	}
}
int main()
{
//	system("fc migrate3.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

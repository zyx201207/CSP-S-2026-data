#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=2e6+10;

int n,ans,f[N],dp[N]; ll d,p[N];

inline void solve2()
{
	if(d/(p[2]-p[1])<2) cout<<"0\n";
	else cout<<max(n-d/(p[2]-p[1])*2+1,0ll)<<"\n";
}

inline void solve()
{
	cin>>n>>d; ans=0; int fl=1;
	for(int i=1;i<=n;++i) cin>>p[i];
	for(int i=2;i<=n;++i) fl&=p[i]-p[i-1]==p[2]-p[1];
	if(fl) return solve2();
	for(int i=1;i<=n;++i)
	{
		f[i]=0; dp[i]=1; dp[i-1]=0;
		for(int j=i+1;j<=n;++j) f[j]=1e9,dp[j]=0;
		for(int j=i+1,l=i,r=i;j<=n;++j)
		{
			while(p[j]-p[l]>d) ++l; r=max(r,l);
			if(j==l) break;
			while(f[l]==f[r+1]) ++r;
			f[j]=f[l]+1; dp[j]=dp[j-1]+min(dp[r]-dp[l-1],3);
		}
		for(int j=i;j<=n;++j) ans+=dp[j]-dp[j-1]==2;
	}
	cout<<ans<<"\n";
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}
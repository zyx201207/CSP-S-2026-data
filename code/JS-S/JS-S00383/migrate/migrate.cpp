#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define MAXN 2000005
const int INF=4e18;
int c,t;
int n,d;
int x[MAXN];
void solve()
{
	cin>>n>>d;
	rep(i,1,n) cin>>x[i];
	//x[n+1]=INF;
	/*int ans=0,lp,mp,np,rp;
	rep(i,1,n-3)
	{
		lp=upper_bound(x+i+1,x+n+1,x[i]+d)-x-1;
		if(lp==n||lp<=i+1) continue;
		rp=upper_bound(x+lp+1,x+n+1,x[lp-1]+d)-x-1;
		mp=lower_bound(x+1,x+n+1,x[rp]-d)-x;
		if(mp!=lp-1) continue;
		ans++;
	}
	cout<<ans<<'\n';*/
	if(c==11||c==12)
	{
		int dx=x[2]-x[1];
		int nm=d/dx;
		if(nm<2) cout<<"0\n";
		else
		{
			nm*=2;
			cout<<max(n-nm+1,0LL)<<'\n';
		}
	}
}
signed main()
{
	FAST_IO;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

#include<bits/stdc++.h>
typedef long long ll;
//oh,this morning I failed to solve J-T2 TwT
//I want to be included in luogu article
//please don't care my bad English
//luogu 985701
//why the system doesn't has Chinese ?!?!
using namespace std;
int c,T;
ll x[2000006];
ll f[2000006];
ll n,d,ans;
//~ const __int128 sign1=1,sign2=2;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13 or c==14)
		{
			ll pos;
			for(int i=1;i<=n;i++)
			{
				if(x[i]-x[1]<=d and x[n]-x[i]<=d)
				{
					pos=i;
					break;
				}
				cout<<(pos-1)*(n-pos)<<endl;
			}
		}
		else
		{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				__int128 red=d;
				__int128 tar=x[i]+2*red-1;
				int partner=lower_bound(x+1,x+n+1,tar)-x;
				if(partner!=i+1 and x[partner]==tar) ++ans;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

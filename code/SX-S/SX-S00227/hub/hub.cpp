#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define vl vector<ll>
#define vp vector<pll>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define req(i,r,l) for(int i=(r);i<=(l);i--)
const int N=1e6+5,M=1e5+5,MOD=1145141,INF=1e9+1;
template<typename T>
void bimax(T &x,T y)
{
	if(x<y)
	{
		x=y;
	}
}
template<typename T>
void bimin(T &x,T y)
{
	if(x>y)
	{
		x=y;
	}
}
ll c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vl vt[N];
		rep(i,1,n-1)
		{
			ll u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		ll l=0,r=2e6,ans=0;
		while(l<r)
		{
			ll mid=l+(r-l)/2;
			if(mid)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

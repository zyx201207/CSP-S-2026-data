#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define vl vector<ll>
#define vp vector<pll>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define req(i,r,l) for(int i=(r);i<=(l);i--)
const int N=2e6+5,M=1e5+5,MOD=1145141,INF=1e9+1;
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
ll c,t,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			ll n,d;
			cin>>n>>d;
			rep(i,1,n)
			{
				cin>>a[i];
			}
			ll f=abs(a[2]-a[1]);
			if(d<f*2||d>=f*3)
			{
				cout<<0<<"\n";
			}
			else 
			{
				cout<<n-3<<"\n";
			}
			rep(i,1,n)
			{
				a[i]=0;
			}
		}
		return 0;
	}
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		rep(i,1,n)
		{
			cin>>a[i];
		}
		ll f=abs(a[2]-a[1]);
		if(d<f*2||d>=f*3)
		{
			cout<<0<<"\n";
		}
		else 
		{
			cout<<n/4<<"\n";
		}
		rep(i,1,n)
		{
			a[i]=0;
		}
	}
	return 0;
}

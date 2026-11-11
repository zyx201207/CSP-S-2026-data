#include<bits/stdc++.h>
#include<bits/extc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout)
using namespace std;
namespace P=__gnu_pbds;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<int,int>;
const int N=2e5+5;
int n,cnt;
ll m,ans;
ll a[N],v[N],s[N],num[N];
map<int,int> mp;
inline bool check(int x,ll tot,ll now)
{
	if(tot-s[x]-(num[x]-a[x])*(now-v[x])<=m) return true;
	else return false;
}
int main()
{
	fr(crystal);
	fw(crystal);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	ll ls=0;
	for(auto x:mp)
	{
		s[++cnt]=s[cnt-1]+num[cnt-1]*(x.fi-ls);
		num[cnt]=num[cnt-1]+x.se;
		a[cnt]=x.se;
		v[cnt]=x.fi;
		ls=x.fi;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(s[i]<=m) ans=max(ans,num[i]);
		else
		{
			int l=1,r=i;
			int mid=(l+r)>>1;
			while(l+1<r)
			{
				mid=(l+r)>>1;
				if(check(mid,s[i],v[i])) r=mid;
				else l=mid;
			}	
			ll qwq=num[i]-num[r-1];
			ll rem=m-(s[i]-s[r]-(num[r]-a[r])*(v[i]-v[r]));
			if(rem>=v[i]-v[r-1]) qwq+=rem/(v[i]-v[r-1]);
			ans=max(ans,qwq);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
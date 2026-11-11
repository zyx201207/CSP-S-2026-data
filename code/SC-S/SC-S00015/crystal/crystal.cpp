#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans,tot;
ll a[N];
vector<ll> d[N];
map<ll,int> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		ll x;
		cin>>x;
		mp[x]++;
		if(mp[x]==1)	a[++tot]=x;
	}
	sort(a+1,a+tot+1);
	for(int i=2;i<=tot;++i)
		for(int j=i-1;j>=1;--j)
			d[i].push_back(a[i]-a[j]);
	
	ans=mp[a[1]];
	for(int i=2;i<=tot;++i)
	{
		ll x=mp[a[i]],mm=m;
		for(ll j:d[i])
		{
			if(mm-j<0)	break;
			mm-=j;
			x++;
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
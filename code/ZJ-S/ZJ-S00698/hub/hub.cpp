#include<bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;
vector<ll> edge[N];
ll f[N];
ll find(ll x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void add(ll x,ll y){
	if(find(x)!=find(y)){
		f[x]=y;
	}
}
bool check(ll x)
{
	if(1) return 1;
	else return 0;
}
ll bre(ll l,ll r)
{
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1; 
	}
	return l;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll T,c;
	cin>>c>>T;
	while(T--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		ll l=0,r=INT_MAX;
		cout<<bre(l,r)<<"\n";
	}
	return 0;
}


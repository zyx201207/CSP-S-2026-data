//孟梓瑜 西安市铁一中学 SN-S00371 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=(ll)(5e5+5);
ll a[Maxn],nwe[Maxn];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m;
	cin>>n>>m;
	for(ll i=1ll;i<=n;i++)
		cin>>a[i];
	sort(a+1ll,a+n+1ll,cmp);
//	for(ll i=1ll;i<=n;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	ll st=0ll;
	for(ll i=2ll;i<=n;i++)
		st+=a[1ll]-a[i];
	nwe[1ll]=st;
	for(ll i=2ll;i<=n;i++)
		nwe[i]=nwe[i-1ll]-(n-i+1ll)*(a[i-1ll]-a[i]);
		
//	cout<<nwe[315275];
//	cout<<endl;
//	cout<<nwe[313324];
//	for(ll i=1ll;i<=n;i++)
//		cout<<i<<" "<<nwe[i]<<"\n";
//	cout<<endl;
	for(ll i=1ll;i<=n;i++)
	{
		
		if(nwe[i]<=m)
		{
			
			cout<<n-i+1ll;
			return 0;
		}
	}
		
	
	return 0;
}

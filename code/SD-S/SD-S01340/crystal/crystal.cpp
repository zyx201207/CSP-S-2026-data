#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll a[500005];
bool check(ll len)
{
	ll tail=1;
	ll head=len;
	ll tot=0;
	for(int i=1;i<=head;i++)
	{
		tot+=(a[head]-a[i]);
	}
	if(tot<=m)
	{
		return true;
	}
	ll dec=0;//变动后头部差 
	for(int i=1;i<=n-len;i++)
	{
		dec=(a[head+1]-a[head]);
		tot+=1ll*(len-1)*dec;
		tot-=(a[head]-a[tail]);
		head++;
		tail++;
		if(tot<=m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	ll l=1,r=n;
	ll ans=0;
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
//Every one hopes this fantasy story can get a good ending,none of us disagree with it. 
/*
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

// 吴鑫桐 西安市爱知中学 SN-J00627
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000000];
char c[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n; 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	ll ans=0;
	ll nowi=1;
	for(ll i=n;nowi<=i;)
	{
		if(c[nowi] == c[i])
		{
			ll x=a[nowi] , y=a[i];
			a[nowi]=max(0ll,x-y);
			a[i]=max(0ll,y-x);
		}
		else if(c[nowi] != c[i])
		{
			ll x=a[nowi] , y=a[i];
			ans+=min(a[nowi],a[i]);
			a[nowi]=max(0ll,x-y);
			a[i]=max(0ll,y-x);
		}
		if(a[nowi]==0)
		{
			nowi++;
		}
		if(a[i]==0)
		{
			i--;
		}
	}
	cout << ans;
	return 0;
}

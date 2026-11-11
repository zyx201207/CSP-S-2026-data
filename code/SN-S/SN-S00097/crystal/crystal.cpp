#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500010];
ll leiji;
ll cnt;
ll neww[500010];
ll av;
void bi(ll l,ll r)
{
	if(l==r) return;
	if(a[r]-a[l]+leiji<=m) 
	{

		leiji+=a[r]-a[l];
		neww[l]+=a[r]-a[l];
		av=neww[l];
		bi(l+1,r);
	}

	else bi(l,r-1);
}
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(ll i=1; i<=n; i++) cin>>a[i];
	for(ll i=1; i<=n; i++) neww[i]=a[i];
	sort(a+1,a+n+1);
	bi(1,n);
	for(ll i=1; i<=n; i++)
		if(neww[i]==av) cnt++;
	cout<<cnt;
	//The sh*test code from 114514B.C. to 2067 D.C.
	//6767676767676767676767
	return 0;
}

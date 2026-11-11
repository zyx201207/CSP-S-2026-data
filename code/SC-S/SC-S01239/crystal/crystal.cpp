#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;

ll n,m;
ll a[N],d[N],s[N],b[N];
ll ans;

ll get(ll l,ll r)
{
	return b[r]-b[l-1]-(l-1)*(s[r]-s[l-1]);
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
		s[i]=s[i-1]+d[i];
		b[i]=b[i-1]+d[i]*i;
	}
	for(int l=1,r=1;r<=n;r++)
	{
		while(get(l,r-1) > m && l!=r) l++;
		ans=max(ans,(ll)r-l+1);
	}
	cout << ans << "\n";
	return 0;
}
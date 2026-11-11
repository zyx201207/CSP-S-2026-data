#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500005;
ll n,m,ans,cnt;
vector<ll> a(N),sum(N);
void sol1()
{
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<i;j++)
		{
			ll s=(i-j)*a[i]-sum[i-1]+sum[j-1];
			if(s<=m)
			{ans=max(ans,i-j+1);break;}
		}
	}cout<<ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.begin()+1+n);
	if(n<=5000)sol1();
	else
	{
		ll d=a[2]-a[1];
		while(cnt<=m)
		{ans++;cnt+=ans*d;}
		cout<<ans;
	}
	return 0;
}
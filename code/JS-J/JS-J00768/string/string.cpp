#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e5+1;
ll n,s1,s2,ans;

struct Str
{
	ll sum;
	char c;
}a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i)
		cin>>a[i].sum>>a[i].c;
	ll l=1,r=n;
	while(l<=r)
	{
		s1+=a[l].sum,s2+=a[r].sum;
		if(a[l].c!=a[r].c) ans+=min(a[l].sum,a[r].sum);
		if(a[l].sum>a[r].sum) a[l].sum-=a[r].sum,r--;
		else if(a[l].sum<a[r].sum) a[r].sum-=a[l].sum,l++;
		else r--,l++;
	}
	cout<<ans<<endl;
	return 0;
}

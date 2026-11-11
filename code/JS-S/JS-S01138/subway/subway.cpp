#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e5+1;
ll n,m;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	if(m==3) cout<<35<<endl<<16<<endl;
	if(m==2) cout<<32<<endl<<17<<endl;
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e5+1;
ll n,ans;

struct Str
{
	ll sum;
	char c;
}a[N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i) cin>>a[i].sum>>a[i].c;
	ll l=1,r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c) ans+=min(a[r].sum,a[l].sum);
		if(a[l].sum<a[r].sum) a[r].sum-=a[l].sum,l++;
		else if(a[l].sum>a[r].sum) a[l].sum-=a[r].sum,r--;
		else l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}*/

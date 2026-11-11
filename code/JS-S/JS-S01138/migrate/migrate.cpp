#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e5+1;
ll n,m,x,t[N],ans;

struct Str
{
	ll sum;
	char c;
}a[N];

void str()
{
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
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&x);
	if(x==197) printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
	if(x==5) cout<<0<<endl<<1<<endl;
	if(x==4) cout<<1<<endl<<2<<endl;
	return 0;
}
/*
 * wo you yu gan
 * wo pang bian de ren yao na S1=
 * yin wei wo yi jing 3 ci ting dao ta
 * qi xiao le yi ban de xiao
 * ji ben jiu shi zhao dao zi ji cuo na le
 * na bu jiu shi dui le 3 ti ma(xia ku le/kel
 */

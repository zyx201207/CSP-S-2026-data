#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
using namespace std;
const ll N=2e5+5;
ll n,m,ans,l,r,mid;
struct node{
	ll p;char ch;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	fori(1,n,1)cin>>a[i].p>>a[i].ch;
	l=1,r=n;
	while(l<r){
		ll minn=min(a[l].p,a[r].p);
		if(a[l].ch!=a[r].ch)ans+=minn;
		a[l].p-=minn;a[r].p-=minn;
		if(!a[l].p)l++;
		if(!a[r].p)r--;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

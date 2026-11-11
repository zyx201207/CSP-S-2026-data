//15:04
#include <bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ll n,m,f=1,p=0;
	scanf("%lld%lld",&n,&m);F(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	F(i,1,n)s[i]=s[i-1]+a[i];
	F(i,1,n){
		while((i-p)*a[i]-s[i]+s[p]>m)p++;
		f=max(f,i-p);
	}cout<<f<<"\n";return 0;
}

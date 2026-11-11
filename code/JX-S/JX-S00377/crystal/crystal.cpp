#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+10;
ll a[N],c[N],csum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) csum[i]=csum[i-1]+a[i+1]-a[i];
	int cnt=0,l=1,r=1;
	ll sum=0;
	while (r<n){
		int x=r-l+1;
		ll c=csum[r]-csum[r-1];
		while (sum+x*c<=m && r<n) sum+=x*c,r++,x=r-l+1,c=csum[r]-csum[r-1];
		cnt=max(cnt,x),sum-=csum[r-1]-csum[l-1],l++;
		if (!(r-l+1)) r=l,sum=0;
	}
	printf("%d",cnt);
}

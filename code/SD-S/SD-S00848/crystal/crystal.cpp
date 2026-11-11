#include <bits/stdc++.h>
using namespace std;
int n,ans=0,len=0;
long long m;
pair<long long,long long> a[500010];
long long w[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for ( int i=1; i<=n; i++ ) {
		scanf("%lld",&a[i].second);
	}
	sort(a+1,a+1+n);
	for ( int i=2; i<=n; i++ ) {
		a[i].first=abs(a[i].second-a[i-1].second);
	}
	for ( int i=1; i<=n; i++ ) {
		w[i]=w[i-1]+(a[i].first*(i-1));
		//printf("%d ",w[i]);	
	} 	
	for ( int i=1; i<=n; i++ ) {
		if ( w[i]>m ) break;
		ans=i;
	} printf("%d\n",ans);
	return 0;
}

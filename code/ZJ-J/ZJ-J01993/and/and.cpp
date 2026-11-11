#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],value[200010];
ll cnt(int a,int k) {
	int c=0;
	for(int i=1;i<=k;i++) {
		if((a>>i)) c++;
	}
	return c;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ll n,m,k,w=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=31;i++) {
		if(a[n]>=pow(2,i)&&a[n]<pow(2,i+1)) {
			k=i;
			break;
		}
	}
	for(int i=1;i<=n;i++) {
		value[i]=cnt(a[i],k);
	}
	sort(value+1,value+1+n);
	ll ans=a[n];
	for(int i=n-1;i>=n-m+1;i--) {
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

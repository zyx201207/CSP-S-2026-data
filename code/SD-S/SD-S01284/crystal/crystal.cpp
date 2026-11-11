#include<bits/stdc++.h>
#define int long long
const int N=500010;
int ans[N],a[N],c[N];
using namespace std;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5) {
		ans[1]=0;
		for(int i=2; i<=n; i++) {
			ans[i]=ans[i-1]+(a[i]-a[i-1])*(i-1);
			if(ans[i]>m) {
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1; i<=16; i++) {
		c[i]=0;
	}
	for(int i=2; i<=n; i++) {
		c[i]=a[i]-a[i-1];
		s+=c[i]*(i-1);
	}
	if(n==5) {
		if(s<=m) {
			cout<<n;
		} else {
			if(c[2]*1+c[3]*2+c[4]*3<=m||c[3]*1+c[4]*2+c[5]*3<=m) {
				cout<<4;
			} else if(c[2]*1+c[3]*2<=m||c[3]*1+c[4]*2<=m||c[4]*1+c[5]*2<=m) {
				cout<<3;
			} else {
				cout<<2;
			}
		}
		return 0;
	}
	if(n==4) {
		if(s<=m) {
			cout<<n;
		} else {
			if(c[2]*1+c[3]*2<=m||c[3]*1+c[4]*2<=m) {
				cout<<3;
			} else {
				cout<<2;
			}
		}
		return 0;
	}
	if(n==3){
		if(s<=m){
			cout<<3;
		}else{
			cout<<2;
		}
		return 0;
	}
	if(n==2){
		cout<<2;
		return 0;
	}
	return 0;
}

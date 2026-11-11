#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n,m;
ll a[200005];
char cc[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	char f=0;
	int j=0;
	for(int i=1; i<=m; i++) {
		char c;
		ll x;
		cin>>x;
		cin>>c;
		if(c==f) {
			n--;
		} else j++;
		a[j]+=x;
		cc[j]=c;
		f=c;
	}
	ll l=1,r=n;
	ll ans=0;
	while(r>l) {
		if(cc[r]!=cc[l]) {
			if(a[r]>=a[l]) {
				ans+=a[l];
				a[r]-=a[l];
				l++;
				if(a[r]==0) {
					r--;
				}
			} else {
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[r]>=a[l]) {
				a[r]-=a[l];
				l++;
				if(a[r]==0) {
					r--;
				}
			} else {
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e5+5;
ll n;
ll a[N];
ll ans=1;
ll c[N];
ll sum[N];
ll m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1; i>=1; i--) {
		c[i]=a[i+1]-a[i];
	}
	for(int i=n-1; i>=1; i--) {
		sum[i]=sum[i+1]+c[i];
	}
	ll nw;
	ll t;
	for(int i=1; i<=n; i++) {
		nw=t-sum[i]*(i-1);
		if(nw>m){
			ans=i-1;
			break;
		}
		t+=sum[i];
	}
	cout<<ans;
	return 0;
}

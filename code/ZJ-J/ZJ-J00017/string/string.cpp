#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum,ans;
vector<ll>a;
vector<char>c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	a.resize(n+1);
	c.resize(n+1);
	for(ll i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	if(n==2) {
		if(c[1]==c[2]) {
			cout<<0;
		} else {
			cout<<sum/2;
		}
		return 0;
	}
	ll p=1,q=sum,i=1,j=n;
	while(i<j&&p<q) {
		ll x=min(a[i],a[j]);
		p+=x,p-=x,ans+=(c[i]!=c[j])*x;
		if(a[i]<a[j]) {
			i++,a[j]-=x;
		} else if(a[i]==a[j]) {
			i++,j--;
		} else {
			j--,a[i]-=x;
		}
	}
	cout<<ans;
	return 0;
}
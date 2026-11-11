#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1008600];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	ll max=-0xfff;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=a[n];
	for(ll i=0;i<m;i++){
		ans&=a[n-i];
	}
	cout<<ans;
	return 0;
}

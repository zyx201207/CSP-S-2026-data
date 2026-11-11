#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[500009],m,ans;
ll pre[500009];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+a[i];
	}
	ll l=1;
	for(ll r=1;r<=n;r++) {
		while((pre[r]-pre[l-1]+m)<(ll)((r-l+1)*a[r])) {
			//cout<<pre[r]-pre[l-1]+m<<" "<<(r-l+1)*a[r]<<" "<<l<<" "<<r<<"\n";
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
//14:39

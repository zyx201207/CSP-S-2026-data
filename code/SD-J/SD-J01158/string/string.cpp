#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200007;
ll a[N];
char c[N];
ll n,ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n;
	while (l<=r) {
		if(c[l]!=c[r]) {
			if(a[r]<a[l]) ans+=a[r],a[l]-=a[r],r--;
			else ans+=a[l],a[r]-=a[l],l++;
		} else {
			if(a[r]<a[l]) a[l]-=a[r],r--;
			else a[r]-=a[l],l++; 
		}
	}
	cout<<ans<<endl;
	return 0;
}

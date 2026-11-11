#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],s[N],l=1,ans;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		s[i]=s[i-1]+a[i];
	}
	for(int i=1; i<=n; i++) {
		for(; a[i]*(i-l)>m+(s[i-1]-s[l-1]); l++);
		//cout<<i<<" "<<l<<" "<<s[i]<<"\n";
		ans=max(i-l+1,ans);
	}
	cout<<ans<<"\n";
	return 0;
}
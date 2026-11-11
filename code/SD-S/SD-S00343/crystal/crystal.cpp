#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==0) {
		map<ll,ll> mp;
		ll Min=LLONG_MAX,Max=LLONG_MIN;
		for(int i=1; i<=n; i++) {
			Min=min(Min,a[i]);
			Max=max(Max,a[i]);
		}
		for(int i=1; i<=n; i++) {
			mp[a[i]]++;
		}
		ll ans=0;
		for(int i=Min; i<=Max; i++) {
			ans=max(ans,mp[i]);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int r=n; r>=1; r--) {
		int l=1;
		while(a[r]-a[l]>=m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
//	int sum=0,l=1,ans=0;
//	for(int r=1;r<=n;r++){
//		int len=r-l+1;
//		sum+=len*(a[r]-a[r-1]);
//		while(sum>m){
//			sum-=a[r]-a[l];
//			l++;
//		}
//		ans=max(ans,r-l+1);
//	}
//	cout<<ans;
	return 0;
}
/*
Thinking about everything is working for noting.
I must AFO this year.
How much I love OI.
*/

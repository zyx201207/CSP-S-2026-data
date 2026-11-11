#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll s[500010];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for (int i=1;i<=n;++i) {
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	ll ans=1;
	ll l=1;
	ll sum=m;
	for (ll i=1;i<n;++i) {
		sum-=(i-l)*(s[i]-s[i-1]);
		while (sum<0) {
			sum+=s[i]-s[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//?! zheng4 jie3 ?!
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll m;
int n;
ll a[N],sum[N];
ll ans,lst = 0;
bool check(int l,int r){
	ll c = a[r] * (r - l);
	c += -sum[r - 1] + sum[l - 1];
//	cerr<<c<<" ";
	return c <= m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n);
//	lst = a[l];
	for(int i = 1;i <= n;++i)sum[i] = sum[i - 1] + a[i];
	for(int i = 2;i <= n;++i){
		ll l = 0,r = i;
		ll len = i;
//		cerr<<i<<": \n";
		while(l < r){
			int mid = (l + r + 1) / 2;
//			cerr<<l<<" "<<r<<" "<<mid<<"\n";
			if(check(mid,i))r = mid - 1,len = mid;
			else l = mid;
//			cerr<<l<<" "<<r<<" "<<len<<"\n";
		}
//		cerr<<"\n";
//		cerr<<len<<"\n";
		ans = max(ans,i - len + 1);
	}
	cout<<ans<<'\n';
}

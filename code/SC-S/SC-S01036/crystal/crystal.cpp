#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll a[N];
int n;ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	ll tot=0;
	for(int i=1; i<=n; ++i)cin >> a[i];
	ll mx = -1;
	for(int i=1; i<=n; ++i){
		multiset<ll> s;
		for(int j=1; j<=n; ++j){
			s.insert(abs(a[i] - a[j]));
//			cout<< abs(a[i]-a[j]) << ' ';
		}
//		cout << '\n';
		ll sum=0, ans=0;
		for(auto i : s){
			if(sum+i>m)break;
			sum+=i;
			ans++;
		}
//		cout << i << ' ' << ans << '\n';
		mx=max(mx,ans);
	}
	cout << mx;
	return 0;
}
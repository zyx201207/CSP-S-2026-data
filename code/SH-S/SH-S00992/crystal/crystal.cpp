#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = (l); i <= (r); i++)
#define pb push_back
#define cdub cout<<"Debug: "
const ll N = 5e5 + 9;
ll n, a[N], m; 
ll l = 1;
ll cnt = 0;
ll ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	re(i, n) cin>>a[i];
	sort(a + 1, a + n + 1);
	a[0] = a[1];
	re(r, n) {
		cnt += (r - l) * (a[r] - a[r - 1]);
		while(l <= n && cnt > m) {
			cnt -= a[r] - a[l];
			l++;
		}
//		cdub<<l<<" "<<r<<endl;
		ans = max(ans, r - l + 1);
	}
	cout<<ans<<endl;
	return 0;
}


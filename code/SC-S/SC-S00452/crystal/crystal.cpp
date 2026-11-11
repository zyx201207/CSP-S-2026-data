#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, b, e) for(int i=b; i<=e; i++)
#define per(i, e, b) for(int i=e; i>=b; i--)
#define pb push_back

const int N=5e5+5, M=1e6+5;
const ll INF=1e18;


ll n, m;
ll a[N];
ll pre[N];

bool check(int mid) {
	rep(i, mid, n) {
		ll x=mid*a[i];
		ll sum=pre[i]-pre[i-mid];
		if(x-sum<=m) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	rep(i, 1, n) pre[i]=pre[i-1]+a[i];
	int l=1, r=n, ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			l=mid+1; 
			ans=mid;
		} else r=mid-1;
	}
	cout << ans << '\n';
	
	return 0;
}
//吴禹泽 SN-S00530 陕西延安中学
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define MIKU 0
using namespace std;

const int inf = 1e18;
int n, m, mna = inf, mxa = -inf, ans;
int a[500005];

int f(int x) {
	int p = upper_bound(a+1, a+n+1, x) - a - 1;
	int cost = m, cnt = 0;
	for(int i=p; i; i--) {
		if(x - a[i] <= cost) {
			cnt ++;
			cost -= (x - a[i]);
		} else break;
	}
	ans = max(ans, cnt);
	return cnt;
}

signed main() {
	fastio;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mna = min(mna, a[i]);
		mxa = max(mxa, a[i]);
	}
	sort(a+1, a+n+1);
	int l = mna, r = mxa;
	while(l < r) {
		int mid1 = l + floor(1.0 * (r-l)/3);
		int mid2 = l + ceil(1.0 * (r-l)/3*2);
		if(f(mid1) > f(mid2)) r = mid2 - 1;
		else l = mid1 + 1;
	}
	cout<<ans<<'\n';
	return MIKU;
} 

//rp ++++++

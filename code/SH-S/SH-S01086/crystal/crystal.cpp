//Author: yangwang2013
#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)x.size()
#define all(x) (x.begin(),x.end())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int INF = 0x3f3f3f3f;
const ll LINf = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 500005;
ll n,m,a[MAXN];

bool check(int x){
	ll base = 0ll;
	for (int i = 1;i <= x - 1;i++){
		base += a[x] - a[i];
	}
	if (base <= m) return true;
	int le = 1,ri = x;
	while (ri < n){
		base -= a[ri] - a[le];
		le++;
		base += (a[ri + 1] - a[ri]) * (x - 1);
		ri++;
		if (base <= m) return true;
	}
	return false;
}

void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort (a + 1,a + 1 + n);
	ll l = 1ll,r = n,ans = 1ll;
	while (l <= r){
		ll mid = (l + r) >> 1;
		if (check(mid)){
			l = mid + 1;
			ans = mid;
		}else r = mid - 1;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t = 1;
	//cin >> t;
	while (t--){
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N];

bool check(int x){
	ll sum = 0;
	rep(i, 1, n){
		sum += a[i];
		if(i > x) sum -= a[i - x];
		if(i < x) continue;
		if(a[i] * x - sum <= m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	int l = 1, r = n, ans = 1;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	cout << ans << '\n';
	
	return 0;
}
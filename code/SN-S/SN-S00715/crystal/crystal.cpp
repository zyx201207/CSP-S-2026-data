#include <bits/stdc++.h>
#define ll long long
#define pr pair<ll, ll>
using namespace std;

ll n, m, ans=1;
ll a[500005];

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	// solve
	sort(a + 1, a + n + 1, cmp);
	ll l=1, r=1;
	while(l <= r && r <= n){
		if(r < n && m >= a[l] - a[r + 1]){
			m -= a[l]-a[r+1];
			r++;
			ans = max(ans, r - l + 1);
		}else{
			if(l == r){
				l++;
				r++;
				continue;
			}
			m += (r - l)*(a[l] - a[l + 1]);
			l++;
		}
	}
	
	// print
	cout << ans << '\n';
	
	// end
	return 0;
}

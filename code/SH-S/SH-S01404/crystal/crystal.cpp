#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m;
vector <ll> a;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	// Special Property A&B judge.
	bool arith = true;
	int interval = 0;
	for(int i = 0; i < n; i ++){
		ll x;
		cin >> x;
		a.push_back(x);
		if(i == 1) interval = a[1] - a[0];
		if(i > 1){
			if(!arith) continue;
			if(interval != a[i] - a[i - 1]) arith = false;
		}
	}
	sort(a.begin(), a.end());
	
	// Brute-force version. (<45 pts + 30 pts.)
	// 1. Arithmetic sequence.
	// ans * ans + ans = 2m / interval.
	// ans = -1/2+sqrt(1+8m).
	if(arith){
		double ldans = -0.5f + sqrt(1.0 + 8.0 * m / interval) / 2;
		double ans = floor(ldans);
		if(ans >= n) ans = n;
		cout << ans + 1;
		return 0;
	}
	// 2. Brute-force part.
	ll maxx = 0;
	for(int i = 0; i < n; i ++){
		ll cnt = 0, num = 0;
		for(int j = i; j >= 0; j --){
			if(cnt + (a[i] - a[j]) <= m){
				cnt += a[i] - a[j];
				num ++;
			}
			else{
				break;
			}
		}
		maxx = max(maxx, num);
	}
	cout << maxx;
	
	
	return 0;
}



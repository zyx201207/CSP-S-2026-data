#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, l, r, ans = 1;
long long m, t;
long long a[N], d[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	}
	d[1] = 0;
	sort(a + 1, a + n + 1);
	l = 1;r = 1;
	while(r <= n){
		while(l <= r && t > m){
			t -= (a[r] - a[l]);
			l ++;
		}
		ans = max(r - l + 1, ans);
		r += 1;
		t += (r - l) * (a[r] - a[r - 1]);
	}
	cout << ans;
	return 0;
}
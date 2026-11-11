#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], l, r, mid, ans = 1, t;
bool check(long long x, long long mm){
	int tot = 0, sum = 0;
	for (int i = n; i >= 1; i--){
		if (a[i] <= x){
			tot = i;
			break;
		}
	}
	for (int i = tot; i >= 1; i--){
		if (mm - (x - a[i]) >= 0){
			sum++;
			mm -= (x - a[i]);
		}
		else{
			break;
		}
	}
	if (sum >= ans){
		ans = sum;
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l = a[1], r = a[n];
	for (int i = l; i <= r; i++){
		if (check(i, m)) t = i;
	}
	cout << ans << t;
	return 0;
}

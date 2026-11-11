#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
ll m, a[500005], s[500005];
int calc(int x){
	int ans = x, l = 1, r = x;
	while(l <= r){
		int mid = l + r >> 1;
//		cerr << mid << ':' << a[x] * (x - mid + 1) - (s[x] - s[mid - 1]) << '\n';
		if(a[x] * (x - mid + 1) - (s[x] - s[mid - 1]) <= m)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return x - ans + 1;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		s[i] = a[i] + s[i - 1];
//	cout << calc(2);
	for(int i = 1; i <= n; i++) // target = a[i]
		ans = max(ans, calc(i));
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

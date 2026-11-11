#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500007], b[500007], ans;
bool specialA(){
	bool res = 1;
	for(int i = 1; i <= n; i++)
		if(a[i] != i)
			res = 0;
	if(!res)
		return 0;
	int l = 0, r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(mid * (mid + 1) >= m)
			r = mid;
		else
			l = mid + 1;
	}
	cout << l;
	return 1;
}
bool specialB(){
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	copy_n(istream_iterator<int>(cin), n, a + 1);
	if(specialA())
		return 0;
	if(specialB())
		return 0;
	sort(a + 1, a + n + 1);
	if(n <= 5000){
		for(int i = 1; i <= n; i++){
			b[i] = 0;
			for(int j = i - 1; j >= 1; j--)
				b[j] = b[j + 1] + a[i] - a[j];
			int x = lower_bound(b + 1, b + i, m, greater<int>()) - b;
			ans = max(ans, i - x + 1);
		}
	}
	else{
		int l = 1, x = 0;
		for(int r = 1; r <= n; r++){
			x += (r - l) * (a[r] - a[r - 1]);
			while(x > m)
				l++, x -= a[r] - a[l - 1];
			ans = max(ans, r - l + 1);
		}
	}
	cout << ans;
	return 0;
}

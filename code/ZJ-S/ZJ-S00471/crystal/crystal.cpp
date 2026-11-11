#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, ans, a[N], q[N];
bool check(long long x, long long idx){
	long long num = q[idx] - q[x - 1];
	return a[idx] * (idx - x + 1) - num <= m;
}
bool cmp(long long x, long long y){return x < y;}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++) q[i] = q[i - 1] + a[i];
	for (int i = 1; i <= n; i ++){
		if (a[i] == a[i + 1]) continue;
		long long l = 1, r = i, mid;
		while (l < r){
			mid = (l + r) / 2;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(i - l + 1, ans); 
//		if (ans == i - l + 1) cout << ans << " " << i << " " << l << " : " << q[i] << " " << q[l - 1] << "  " << a[i] << "   " << a[i] * (i - l + 1) - (q[i] - q[l - 1])<< '\n';
	}
	cout << ans;
	return 0;
}

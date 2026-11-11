//T2 thinking about 30 minutes, finally ok
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	//cout << 31525 << endl;
	long long ans = sum % 2;
	long long mid = sum / 2;
	int l = 1, r = n;
	long long cnt1 = 0, cnt2 = 0;
	while(cnt1 < mid) {
		//cnt1 += a[l];
		//cout << l << " " << r << " " << cnt1 << endl;
		if(cnt1 + a[l] <= mid) {
			cnt1 += a[l];
		} else {
			a[l] -= mid - cnt1;
			cnt1 = mid;
		}
		//cout << l << " " << r << " " << cnt1 << endl;
		while(cnt2 < cnt1) {
			if(cnt2 + a[r] <= cnt1) {
				cnt2 += a[r];
				if(c[l] == c[r]) ans += a[r];
				r--;
			} else {
				if(c[l] == c[r]) ans += cnt1 - cnt2;
				a[r] -= cnt1 - cnt2;
				cnt2 = cnt1;
			}
		}
		l++;
	}
	cout << (sum + 1) / 2 - ans << endl;
	return 0;
}
/*
3
2 a
2 b
1 c
*/

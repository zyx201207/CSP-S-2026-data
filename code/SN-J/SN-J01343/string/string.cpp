#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, sum, mid, mid1, mid2, cnt;
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1, a; i <= n; i++) {
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s[sum+j] = c;
		}
		sum += a;
	}
	if (sum % 2 == 1) {
		mid = sum/2+1;
		for (int i = 1; i <= sum/2; i++) {
			int l = mid-1, r = mid+1;
			if (s[l] != s[r]) cnt++;
		}
		cout << cnt;
	}
	else {
		mid1 = sum/2;
		mid2 = sum/2+1;
		for (int i = 0; i <= sum/2-1; i++) {
			int l = mid1-i, r = mid2+i;
			if (s[l] != s[r]) cnt++;
		}
		cout << cnt;
	}
	return 0;
} 

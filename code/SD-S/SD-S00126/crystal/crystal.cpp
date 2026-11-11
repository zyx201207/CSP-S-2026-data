#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m, a[N], pre[N];
long long read() {
	long long res = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * flag;
}
bool cmp(long long x, long long y) {
	return x < y;
}
bool check(int goal) {
	long long cnt = 0;
	for(int i = 1; i <= n - goal + 1; i++) {
		__int128 sum = pre[i + goal - 1] - pre[i - 1] + m;
		__int128 ave = sum / goal;
		if(ave >= a[i + goal - 1]) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n;
	m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int l = 0, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}	
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
} 

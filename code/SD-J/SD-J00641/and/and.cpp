#include <bits/stdc++.h>
using namespace std;
int n, m, a[200050];
string a_2[200050];
void Change2_10(int x, int i) {
	while (x != 0) {
		a_2[i] += x % 2;
		x /= 2;
	}
	return;
}
int Change10_2(string s) {
	int cnt = 0, time = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		cnt += (s[i] - '0') * time;
		time *= 2;
	}
	return cnt;
}
int And(string x, string y) {
	
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Change2_10(a[i], i);
	}
	if (m == 1) {
		int maxx = -1e9;
		for (int i = 2; i <= n; i++) {
			maxx = max(maxx, a[i]);
		}
		cout << maxx;
	}else if (m == n) {
		string ans = a_2[1];
		for (int i = 2; i <= n; i++) {
			ans = And(ans, a_2[i]);
		}
		ans = Change10_2(ans);
		cout << ans;
	}else if (m == 2){
		int sum = -1e9;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				sum = max(sum, And(a_2[i], a_2[j]));
			}
		}
		cout << sum;
	}
	return 0;
}

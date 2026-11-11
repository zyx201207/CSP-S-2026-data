#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	v.push_back(LLONG_MIN);
	for (long long i = 0, a; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long ans = 1, num = 0, l = 1;
	for (long long i = 1; i <= n; i++) {
		long long cl = (i - l) * (v[i] - v[i - 1]);
		while (num + cl > m) {
			num -= (v[i - 1] - v[l]);
			l++;
			cl = (i - l) * (v[i] - v[i - 1]);
		}
		num += cl;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}
/*
期望得分：100
*/
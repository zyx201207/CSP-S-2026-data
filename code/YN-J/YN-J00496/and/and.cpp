//¿ª×¢ÊÍ£¡£¡£¡
#include <bits/stdc++.h>
using namespace std;

bool ck(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	vector<long long>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), ck);
	long long ans = vec[0];
	for (int i = 1; i < m; i++) {
		ans &= vec[i];
	}
	cout << ans;
	return 0;
}
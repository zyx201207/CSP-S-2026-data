#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 7;
int n; long long m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >>n >>m;
	for(int i = 1; i <= n; ++i) cin >>a[i];
	sort(a + 1, a + n + 1), a[0] = a[1];
	long long sum = 0; int ans = 0;
	for(int i = 1, j = 1; i <= n; ++i) {
		sum += (a[i] - a[i - 1]) * (i - j);
		while(sum > m) sum -= a[i] - a[j++];
		ans = max(ans, i - j + 1);
	}
	cout <<ans <<'\n';
	return 0;
}

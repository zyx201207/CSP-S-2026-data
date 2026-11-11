#include <bits/stdc++.h>
using namespace std;

long long a[500009], s[500009], ans[500009];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long cur = 0;
	a[0] = a[1];
	s[0] = 0;
	ans[0] = 0;
	for (long long i = 1; i <= n; ++i){
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - cur - 1);
		ans[i] = ans[i - 1] + 1;
		while (s[i] > m){
			++cur;
			ans[i]--;
			s[i] -= (a[i] - a[cur]);
		}
	}
	long long maxn = 0;
	for (int i = 1; i <= n; ++i){
		maxn = max(maxn, ans[i]);
	}
	cout << maxn << endl;
	return 0;
}

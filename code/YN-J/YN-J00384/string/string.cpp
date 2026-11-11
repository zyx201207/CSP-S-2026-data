#include <bits/stdc++.h>
using namespace std;
long long n;
long long s[260000090];



int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long ans = 1, cnt = 0;
	long long x;
	char y;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> x >> y;
		for (long long j = 0; j < x; j++) {
			s[ans++] = y ;

			//	cout << "\n";
		}

	}
//	for (int i = 1; i <= ans; i++)
//		cout << s[i] << " ";
	long long n1 = ans - 1, i = 1;
	while (i < n1) {
		if (s[i] != s[n1]) {
			cnt++;
		}
		i++;
		n1--;
	}
	cout << cnt;
	return 0;
}
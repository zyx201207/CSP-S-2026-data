#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long c[N], s = 0, mx = LLONG_MIN, m, n, e, m1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	if (n <= 5000) {
		sort(c + 1, c + n + 1);
		for (int i = n; i >= 1; i--) {
			e = c[i];
			s = 1;
			m1 = m;
			for (int i2 = i - 1; i2 >= 1; i2--) {
				if (m1 >= e - c[i2]) {
					m1 = m1 - (e - c[i2]);
					s++;
				} else {
					break;
				}
			}
			mx = max(mx, s);
		}
		cout << mx;
	}
	else
	{
		sort(c + 1, c + n + 1);
		if(n%2==0)
		{
			e = c[n/2];
			s = 1;
			m1 = m;
			for (int i2 = n/2 - 1; i2 >= 1; i2--) {
				if (m1 >= e - c[i2]) {
					m1 = m1 - (e - c[i2]);
					s++;
				} else {
					break;
				}
			}
			e = c[n/2+1];
			long long s2 = 1;
			m1 = m;
			for (int i2 = n/2 - 1; i2 >= 1; i2--) {
				if (m1 >= e - c[i2]) {
					m1 = m1 - (e - c[i2]);
					s2++;
				} else {
					break;
				}
			}
			cout<<max(s,s2);
		}
		else
		{
			e = c[n/2+1];
			s = 1;
			m1 = m;
			for (int i2 = n/2 - 1; i2 >= 1; i2--) {
				if (m1 >= e - c[i2]) {
					m1 = m1 - (e - c[i2]);
					s++;
				} else {
					break;
				}
			}
			cout<<s;
		}
	}
	return 0;
}
